/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:33:11 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/17 15:19:45 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	error(void)
{
	ft_fdprintf(2, "Error\n");
}

// void	order_stack()

int	get_order_of_value(int value, t_array *values)
{
	int	i;
	int order;

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

t_item	create_item_from_value_at(int index, t_array *values)
{
	t_item item;

	item.value = *(int *) get_element_at(values, index);
	item.order = get_order_of_value(item.value, values);
	return (item);
}

void	populate_stack(t_stack *stack, t_array *values)
{
	t_item item;
	int	i;

	i = 0;
	while (i < values->size)
	{
		item = create_item_from_value_at(i, values);
		add_item(stack, item);
		i++;
	}
}


void	print_value_at(t_stack *stack, unsigned long i)
{
	t_item	item;

	if (i >= stack->size)
		return ;
	item = get_item_at(stack, i);
	ft_printf("% 10d - %03d", item.value, item.order);
}

int	main(int argc, char **argv)
{
	t_array	values;
	t_stack	stack_a;
	t_stack	stack_b;

	(void) argc;
	if (create_array(&values, sizeof(int)))
		return (error(), 1);
	if (parse(&values, ++argv))
		return (error(), 2);
	if (create_stack(&stack_a, values.size))
		return (3);
	if (create_stack(&stack_b, values.size))
		return (4);
	populate_stack(&stack_a, &values);

	// pb(&stack_a, &stack_b);
	// rra(&stack_a);
	// pb(&stack_a, &stack_b);
	// sb(&stack_b);

	for (size_t i = 0; i < stack_a.size; i++)
	{
		print_value_at(&stack_a, i);
		print_value_at(&stack_b, i);
		ft_printf("\n");
	}
}
