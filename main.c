/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:33:11 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/22 11:27:37 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	error(void)
{
	ft_fdprintf(2, "Error\n");
}

// void has_dulpicates(t_)

int	get_dots2(int count, char **str)
{
	if (ft_malloc2(count + 1, (void **) str))
		return (1);
	(*str)[count] = 0;
	ft_memset(*str, '.', count);
	return (0);
}

int	get_offset(t_stack *stack_a, t_stack *stack_b)
{
	int 			item;
	int				min;
	unsigned long	i;

	min = INT_MAX;
	i = 0;
	while (i < stack_a->size)
	{
		item = get_item_at(stack_a, i);
		if (item < min)
			min = item;
		i++;
	}
	i = 0;
	while (i < stack_b->size)
	{
		item = get_item_at(stack_b, i);
		if (item < min)
			min = item;
		i++;
	}
	return min;
}

void	print_value_at(t_stack *stack, unsigned long i, int offset)
{
	int 	item;
	char	*dots;

	(void) offset;
	if (i >= stack->size)
	{
		// ft_printf("                                                                                                               ");
		// ft_printf("");
		return ;
	}
	item = get_item_at(stack, i);
	if (get_dots2(item - offset, &dots))
		return ;
	// ft_printf("% 10d - %03d", item, item.order);
	ft_printf("% 10d %-100s", item, dots);
	// ft_printf("% 10d", item);
	free(dots);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	i;
	size_t			size;
	int				offset;

	size = stack_a->size;
	if (stack_b->size > size)
		size = stack_b->size;
	offset = get_offset(stack_a, stack_b);
	i = 0;
	while (i < size)
	{
		print_value_at(stack_a, i, offset);
		print_value_at(stack_b, i, offset);
		ft_printf("\n");
		i++;
	}
}

int	get_order_of_value(int value, t_stack *stack)
{
	unsigned int	i;
	int				order;

	i = 0;
	order = 0;
	while (i < stack->size)
	{
		if (get_item_at(stack, i) < value)
			order++;
		i++;
	}
	return (order);
}

void	populate_stack(t_stack *stack, t_array *values)
{
	ft_memcpy(stack->items, values->elements, values->size * values->bytes);
	stack->size = values->size;
}

int	get_median_value(t_stack *stack)
{
	unsigned int	i;
	int 		item;

	i = 0;
	while (i < stack->size)
	{
		item = get_item_at(stack, i);
		if (get_order_of_value(item, stack) == stack->size / 2)
			break;
		i++;
	}
	return get_item_at(stack, i);
}

void	print_sorted_ratio(t_stack *stack_a, t_stack *stack_b)
{
	int 			sorted;
	unsigned int	i;

	sorted = (stack_a->size > 0) + (stack_b->size > 0);
	i = 1;
	while (i < stack_a->size)
	{
		int item1 = get_item_at(stack_a, i - 1);
		int item2 = get_item_at(stack_a, i);

		if (item1 < item2)
			sorted++;
		i++;
	}
	i = 1;
	while (i < stack_b->size)
	{
		int item1 = get_item_at(stack_b, i - 1);
		int item2 = get_item_at(stack_b, i);

		if (item1 < item2)
			sorted++;
		i++;
	}
	ft_printf("\n%d/%d - %3d%%\n", sorted, stack_a->size + stack_b->size, sorted * 100 / (stack_a->size + stack_b->size));
}

unsigned int	abs_val(int value)
{
	if (value < 0)
		return -value;
	return value;
}

void printb(int value)
{
	for(int i = 0; i < 32; i++)
	{
		ft_printf("%d", !!(value & (1 << (31 - i))));
	}
	ft_printf("\n");
}

void	push_by_median(t_stack *stack_a, t_stack *stack_b)
{
	int		median;
	int		iter;

	median = get_median_value(stack_a);
	iter = stack_a->size;
	while (iter--)
	{
		int item = get_item_at(stack_a, 0);
		if (item < median)
		{
			// if (stack_b->size > 1)
			// {
			// 	int order = get_order_of_value(item, stack_b) - 1;
			// 	int next = get_order_of_value(get_item_at(stack_b, 0), stack_b);
			// 	int offset = order - next;
			// 	ft_printf("%d | %d - %d = %d (%d) | %d\n", item, order, next, offset, abs_val(offset), stack_b->size);
			// 	if (stack_b->size / 2 < abs_val(offset))
			// 		offset += stack_b->size;
			// 	while (offset < 0)
			// 	{
			// 		rotate(stack_b);
			// 		offset++;
			// 	}
			// 	while (offset > 0)
			// 	{
			// 		rotate_reverse(stack_b);
			// 		offset--;
			// 	}
			// }
			push(stack_a, stack_b);
		}
		else
			rotate(stack_a);
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	// while (stack_a->size)
	// {
	// 	int item = get_item_at(stack_a, )
	// }
	int median = get_item_at(stack_a, stack_a->size / 2);

	i = 0;
	while (stack_a->size > 0)
	{
		int item = get_item_at(stack_a, 0);
		push(stack_a, stack_b);
		if (item < median)
			rotate(stack_b);
		// else if (order <= i + (int) stack_a->size / 4)
		// {
		// 	push(stack_a, stack_b);
		// }
	}

	// while (stack_a->size > 1)
	// 	push_by_median(stack_a, stack_b);
	// while (stack_b->size > 0)
	// 	push(stack_b, stack_a);
	// while (stack_b->size > 1)
		// push_by_median(stack_b, stack_a);
	// while (stack_b->size > 0)
	// {
	// 	print_stacks(stack_a, stack_b);
	// 	sleep(1);
	// 	push(stack_b, stack_a);
	// 	int item1 = get_item_at(stack_a, 0);
	// 	int item2 = get_item_at(stack_b, 1);
	// 	if (stack_a->size > 2 && item1 > item2)
	// 		rotate(stack_a);
	// }

	// rotate(stack_a);
	// push(stack_b, stack_a);
	// rotate_reverse(stack_a);
	// swap(stack_a);
	// push(stack_a, stack_b);
	// push(stack_a, stack_b);
	// swap_both(stack_a, stack_b);
	// rotate_reverse_both(stack_a, stack_b);
	// rotate_both(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_array	values;
	t_stack	stack_a;
	t_stack	stack_b;

	// printb(-5);
	// ft_printf("%d\n", abs_val(-5));
	// return (0);

	if (argc == 1)
		return (0);
	if (create_array(&values, sizeof(int)))
		return (error(), 1);
	if (parse(&values, ++argv))
		return (error(), 2);
	if (create_stack(&stack_a, values.size, 'a'))
		return (3);
	if (create_stack(&stack_b, values.size, 'b'))
		return (4);
	populate_stack(&stack_a, &values);
	free_array(&values);
	// print_stacks(&stack_a, &stack_b);
	// sleep(3);
	sort(&stack_a, &stack_b);
	// sort(&stack_a, &stack_b);
	// print_stacks(&stack_a, &stack_b);
	// print_sorted_ratio(&stack_a, &stack_b);
	// ft_printf("done\n");
}
