/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:24:49 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/17 14:36:39 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	rra(t_stack *stack)
{
	ft_printf("rra\n");
	rotate_reverse(stack);
}

void	rrb(t_stack *stack)
{
	ft_printf("rrb\n");
	rotate_reverse(stack);
}

void	rrr(t_stack *stack1, t_stack *stack2)
{
	ft_printf("rrr\n");
	rotate_reverse(stack1);
	rotate_reverse(stack2);
}
