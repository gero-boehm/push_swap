/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:22:22 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/14 11:26:59 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_swap(t_stack *stack)
{
	int	item1;
	int	item2;

	if (stack->size < 2)
		return ;
	item1 = get_item_at(stack, 0);
	item2 = get_item_at(stack, 1);
	set_item_at(stack, 0, item2);
	set_item_at(stack, 1, item1);
}

void	exec_push(t_stack *stack1, t_stack *stack2)
{
	int	item;

	if (stack1->size == 0)
		return ;
	item = get_item_at(stack1, 0);
	stack1->start = normalize_index(stack1, 1);
	stack1->size--;
	set_item_at(stack2, -1, item);
	stack2->start = normalize_index(stack2, -1);
	stack2->size++;
}

void	exec_rotate(t_stack *stack)
{
	int	item;

	if (stack->size < 2)
		return ;
	item = get_item_at(stack, 0);
	stack->start = normalize_index(stack, 1);
	set_item_at(stack, stack->size - 1, item);
}

void	exec_rotate_reverse(t_stack *stack)
{
	int	item;

	if (stack->size < 2)
		return ;
	item = get_item_at(stack, stack->size - 1);
	stack->start = normalize_index(stack, -1);
	set_item_at(stack, 0, item);
}
