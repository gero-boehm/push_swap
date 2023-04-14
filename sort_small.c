/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:36:16 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/14 11:28:03 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	should_swap(t_stack *stack)
{
	int		i;
	int		j;
	int		item_a;
	int		item_b;
	int		order;

	i = 0;
	while (i < 3)
	{
		if (get_item_at(stack, i) == 0)
			break ;
		i++;
	}
	i++;
	j = 0;
	order = 0;
	while (j < 2)
	{
		item_a = get_item_at(stack, i - 1);
		item_b = get_item_at(stack, i);
		order += item_b - item_a;
		i++;
		j++;
	}
	return (order == 1);
}

void	sort_three(t_stack *stack)
{
	if (should_swap(stack))
		swap(stack);
	while (!is_sorted(stack))
		rotate(stack);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 2)
	{
		if (get_item_at(stack_a, 0) < 3)
			push(stack_a, stack_b);
		else
			rotate(stack_a);
	}
	if (get_item_at(stack_a, 0) == 4)
		swap(stack_a);
	if (stack_b->size == 3)
	{
		while (get_item_at(stack_b, 0) != 2)
			rotate(stack_b);
		push(stack_b, stack_a);
	}
	if (get_item_at(stack_b, 0) == 0)
		swap(stack_b);
	push(stack_b, stack_a);
	push(stack_b, stack_a);
}
