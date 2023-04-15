/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:37:59 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/15 10:42:37 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

static int	has_duplicates(t_array *values)
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

static int	get_order_of_value(int value, t_array *values)
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

static void	populate_stack(t_stack *stack, t_array *values)
{
	unsigned long	i;
	int				value;
	int				order;

	i = 0;
	while (i < values->size)
	{
		value = *(int *) get_element_at(values, i);
		order = get_order_of_value(value, values);
		add_item(stack, order);
		i++;
	}
}

void	error(void)
{
	write(2, "Error\n", 6);
}

int	init_stacks(char **argv, t_stack *stack_a, t_stack *stack_b)
{
	t_array	values;

	if (create_array(&values, sizeof(int)))
		return (1);
	if (parse(&values, argv))
		return (free_array(&values), error(), 2);
	if (has_duplicates(&values))
		return (free_array(&values), error(), 3);
	if (create_stack(stack_a, values.size, 'a'))
		return (free_array(&values), 4);
	if (create_stack(stack_b, values.size, 'b'))
		return (free_array(&values), free(stack_a->items), 5);
	populate_stack(stack_a, &values);
	free_array(&values);
	return (0);
}
