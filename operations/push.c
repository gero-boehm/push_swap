/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:25:32 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/17 14:36:13 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	pb(t_stack *a, t_stack *b)
{
	ft_printf("pb\n");
	push(a, b);
}

void	pa(t_stack *b, t_stack *a)
{
	ft_printf("pa\n");
	push(b, a);
}
