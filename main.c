/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:33:11 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/22 15:48:13 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	error(void)
{
	ft_fdprintf(2, "Error\n");
}

int	has_duplicates(t_array *values)
{
	unsigned long	i;
	unsigned long	j;
	int				value;

	i = 0;
	while (i < values->size)
	{
		j = 0;
		value = *(int *) get_element_at(values, i);
		while (j < i)
		{
			if (*(int *) get_element_at(values, j) == value)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_order_of_value(int value, t_array *values)
{
	unsigned long	i;
	int				order;

	i = 0;
	order = 0;
	while (i < values->size)
	{
		if (*(int *) get_element_at(values, i) < value)
			order++;
		i++;
	}
	return (order);
}

void	populate_stack(t_stack *stack, t_array *values)
{
	unsigned long	i;
	t_item			item;

	i = 0;
	while (i < values->size)
	{
		item.value = *(int *) get_element_at(values, i);
		item.order = get_order_of_value(item.value, values);
		add_item(stack, item);
		i++;
	}
}

void printb(int value)
{
	for(int i = 0; i < 32; i++)
	{
		ft_printf("%d", !!(value & (1 << (31 - i))));
	}
	ft_printf("\n");
}


int	get_op_count(t_stack *stack, int order)
{
	unsigned long	i;
	t_item			item;

	i = 0;
	while (i < stack->size)
	{
		item = get_item_at(stack, i);
		if (item.order == order)
			return (i);
		i++;
	}
	return (-1);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	range;

	range = (int) sqrt(stack_a->size) * 14 / 10;

	// for (unsigned long i = 0; i < stack_a->size; i++)
	// {
	// 	t_item item = get_item_at(stack_a, i);
	// 	ft_printf("%10d - %03d\n", item.value, item.order);
	// }

	i = 0;
	while (stack_a->size)
	{
		t_item item = get_item_at(stack_a, 0);
		if (item.order <= i)
		{
			push(stack_a, stack_b);
			rotate(stack_b);
			i++;
		}
		else if (item.order <= i + range)
		{
			push(stack_a, stack_b);
			i++;
		}
		else
			rotate(stack_a);
	}
	while (stack_b->size)
	{
		int rb = get_op_count(stack_b, --i);
		int rrb = stack_b->size - rb;
		if (rb <= rrb)
		{
			while (rb--)
				rotate(stack_b);
		}
		else
		{
			while (rrb--)
				rotate_reverse(stack_b);
		}
		push(stack_b, stack_a);
	}
}

int	main(int argc, char **argv)
{
	t_array	values;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (0);
	if (create_array(&values, sizeof(int)))
		return (error(), 1);
	if (parse(&values, ++argv))
		return (error(), 2);
	if (has_duplicates(&values))
		return (error(), 3);
	if (create_stack(&stack_a, values.size, 'a'))
		return (3);
	if (create_stack(&stack_b, values.size, 'b'))
		return (4);
	populate_stack(&stack_a, &values);
	free_array(&values);
	sort(&stack_a, &stack_b);
	return (0);
}

// 69 16 65 90 4 88 49 12 2 33 31 50 44 82 13 55 5 71 23 15 37 18 96 11 81 20 19 60 38 46 25 52 22 72 54 59 77 85 84 10 95 70 47 40 6 64 53 98 14 28 83 41 89 76 92 21 86 34 80 8 30 32 66 9 61 43 93 62 29 99 27 51 79 75 87 91 39 42 57 26 1 94 78 100 74 24 35 17 7 67 36 97 48 63 3 68 58 45 56 73