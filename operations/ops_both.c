/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_both.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:05:48 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/28 23:06:01 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	swap_both(t_stack *stack1, t_stack *stack2)
{
	ft_printf("ss\n");
	exec_swap(stack1);
	exec_swap(stack2);
}

void	rotate_both(t_stack *stack1, t_stack *stack2)
{
	ft_printf("rr\n");
	exec_rotate(stack1);
	exec_rotate(stack2);
}

void	rotate_reverse_both(t_stack *stack1, t_stack *stack2)
{
	ft_printf("rrr\n");
	exec_rotate_reverse(stack1);
	exec_rotate_reverse(stack2);
}
