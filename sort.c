/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:15:55 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/14 11:26:24 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	sort_phase_1(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		range;
	int		item;

	i = 0;
	range = (int) ft_isqrt(stack_a->size) * 14 / 10;
	while (stack_a->size)
	{
		item = get_item_at(stack_a, 0);
		if (item <= i)
		{
			push(stack_a, stack_b);
			rotate(stack_b);
			i++;
		}
		else if (item <= i + range)
		{
			push(stack_a, stack_b);
			i++;
		}
		else
			rotate(stack_a);
	}
}

static int	get_op_count(t_stack *stack, int order)
{
	unsigned long	i;
	int				item;

	i = 0;
	while (i < stack->size)
	{
		item = get_item_at(stack, i);
		if (item == order)
			return (i);
		i++;
	}
	return (-1);
}

static void	sort_phase_2(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	rb;
	int	rrb;

	i = stack_b->size;
	while (i)
	{
		rb = get_op_count(stack_b, --i);
		rrb = stack_b->size - rb;
		if (rb <= rrb)
		{
			while (rb--)
				rotate(stack_b);
		}
		else
		{
			while (rrb--)
				rotate_reverse(stack_b);
		}
		push(stack_b, stack_a);
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		swap(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	else
	{
		sort_phase_1(stack_a, stack_b);
		sort_phase_2(stack_a, stack_b);
	}
}
