/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:33:11 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/28 01:43:01 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

static void	error(void)
{
	write(2, "Error\n", 6);
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

// int	is_sorted(t_array *values)
// {
// 	int	i;
// 	int	current;
// 	int	last;

// 	if (values->size <= 1)
// 		return (1);
// 	i = 1;
// 	last = *(int *) get_element_at(values, 0);
// 	while (i < (int) values->size)
// 	{
// 		current = *(int *) get_element_at(values, i);
// 		if (current <= last)
// 			return (0);
// 		last = current;
// 		i++;
// 	}
// 	return (1);
// }

int	is_sorted(t_stack *stack)
{
	int	i;

	if (stack->size <= 1)
		return (1);
	i = 0;
	while (i < (int) stack->size)
	{
		if (get_item_at(stack, i).order != i)
			return (0);
		i++;
	}
	return (1);
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
		return (free_array(&values), error(), 2);
	if (has_duplicates(&values))
		return (free_array(&values), error(), 3);
	if (create_stack(&stack_a, values.size, 'a'))
		return (free_array(&values), 3);
	if (create_stack(&stack_b, values.size, 'b'))
		return (free_array(&values), free(stack_a.items), 4);
	populate_stack(&stack_a, &values);
	free_array(&values);
	if (!is_sorted(&stack_a))
		sort(&stack_a, &stack_b);
	free(stack_a.items);
	free(stack_b.items);
	return (0);
}

// 69 16 65 90 4 88 49 12 2 33 31 50 44 82 13 55 5 71 23 15 37 18 96 11 81 20 19 60 38 46 25 52 22 72 54 59 77 85 84 10 95 70 47 40 6 64 53 98 14 28 83 41 89 76 92 21 86 34 80 8 30 32 66 9 61 43 93 62 29 99 27 51 79 75 87 91 39 42 57 26 1 94 78 100 74 24 35 17 7 67 36 97 48 63 3 68 58 45 56 73