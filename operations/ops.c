/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:04:28 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/28 23:06:08 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	swap(t_stack *stack)
{
	ft_printf("s%c\n", stack->label);
	exec_swap(stack);
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

void	rotate_reverse(t_stack *stack)
{
	ft_printf("rr%c\n", stack->label);
	exec_rotate_reverse(stack);
}
