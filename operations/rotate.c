/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:23:24 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/17 14:36:35 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ra(t_stack *stack)
{
	ft_printf("ra\n");
	rotate(stack);
}

void	rb(t_stack *stack)
{
	ft_printf("rb\n");
	rotate(stack);
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	ft_printf("rr\n");
	rotate(stack1);
	rotate(stack2);
}
