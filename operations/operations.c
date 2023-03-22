/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:22:22 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/22 13:57:58 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	exec_swap(t_stack *stack)
{
	t_item	item1;
	t_item	item2;

	if (stack->size < 2)
		return ;
	item1 = get_item_at(stack, 0);
	item2 = get_item_at(stack, 1);
	set_item_at(stack, 0, item2);
	set_item_at(stack, 1, item1);
}

void	exec_push(t_stack *stack1, t_stack *stack2)
{
	t_item	item;

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
	t_item	item;

	if (stack->size < 2)
		return ;
	item = get_item_at(stack, 0);
	stack->start = normalize_index(stack, 1);
	set_item_at(stack, stack->size - 1, item);
}

void	exec_rotate_reverse(t_stack *stack)
{
	t_item	item;

	if (stack->size < 2)
		return ;
	item = get_item_at(stack, stack->size - 1);
	stack->start = normalize_index(stack, -1);
	set_item_at(stack, 0, item);
}

void	swap(t_stack *stack)
{
	ft_printf("s%c\n", stack->label);
	exec_swap(stack);
}

void	swap_both(t_stack *stack1, t_stack *stack2)
{
	ft_printf("ss\n");
	exec_swap(stack1);
	exec_swap(stack2);
}

void	push(t_stack *stack1, t_stack *stack2)
{
	ft_printf("p%c\n", stack2->label);
	exec_push(stack1, stack2);
}

void	rotate(t_stack *stack)
{
	ft_printf("r%c\n", stack->label);
	exec_rotate(stack);
}

void	rotate_both(t_stack *stack1, t_stack *stack2)
{
	ft_printf("rr\n");
	exec_rotate(stack1);
	exec_rotate(stack2);
}

void	rotate_reverse(t_stack *stack)
{
	ft_printf("rr%c\n", stack->label);
	exec_rotate_reverse(stack);
}

void	rotate_reverse_both(t_stack *stack1, t_stack *stack2)
{
	ft_printf("rrr\n");
	exec_rotate_reverse(stack1);
	exec_rotate_reverse(stack2);
}
