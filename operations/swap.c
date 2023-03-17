/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:26:43 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/17 14:36:30 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	sa(t_stack *stack)
{
	ft_printf("sa\n");
	swap(stack);
}

void	sb(t_stack *stack)
{
	ft_printf("sb\n");
	swap(stack);
}

void	ss(t_stack *stack1, t_stack *stack2)
{
	ft_printf("ss\n");
	swap(stack1);
	swap(stack2);
}
