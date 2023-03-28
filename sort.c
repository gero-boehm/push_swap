/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:15:55 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/28 01:52:54 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

static void	sort_phase_1(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		range;
	t_item	item;

	i = 0;
	range = (int) ft_isqrt(stack_a->size) * 14 / 10;
	while (stack_a->size)
	{
		item = get_item_at(stack_a, 0);
		if (item.order <= i)
		{
			push(stack_a, stack_b);
			rotate(stack_b);
			i++;
		}
		else if (item.order <= i + range)
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
	t_item			item;

	i = 0;
	while (i < stack->size)
	{
		item = get_item_at(stack, i);
		if (item.order == order)
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

int	should_swap(t_stack *stack)
{
	int		i;
	int		j;
	t_item	item_a;
	t_item	item_b;
	int		order;

	i = 0;
	while (i < 3)
	{
		if (get_item_at(stack, i).order == 0)
			break ;
		i++;
	}
	j = 0;
	order = 0;
	while (j < 2)
	{
		item_a = get_item_at(stack, (i - 1) % 4);
		item_b = get_item_at(stack, i % 4);
		order += item_b.order - item_a.order;
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

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		swap(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else
	{
		sort_phase_1(stack_a, stack_b);
		sort_phase_2(stack_a, stack_b);
	}
}
