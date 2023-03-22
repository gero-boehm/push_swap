/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:02:44 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/20 12:58:01 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	create_stack(t_stack *stack, size_t size, char label)
{
	if (ft_malloc2(size * sizeof(int), (void **) &stack->items))
		return (1);
	stack->size = 0;
	stack->max_size = size;
	stack->start = 0;
	stack->label = label;
	return (0);
}

unsigned long	normalize_index(t_stack *stack, long index)
{
	return ((index + stack->start + stack->max_size) % stack->max_size);
}

int	add_item(t_stack *stack, int item)
{
	unsigned long	index;

	if (stack->size == stack->max_size)
		return (1);
	index = normalize_index(stack, stack->size++);
	stack->items[index] = item;
	return (0);
}

int	get_item_at(t_stack *stack, long index)
{
	index = normalize_index(stack, index);
	return (stack->items[index]);
}

void	set_item_at(t_stack *stack, long index, int item)
{
	index = normalize_index(stack, index);
	stack->items[index] = item;
}
// int	main(void)
// {
// 	t_stack	stack_a;
// 	t_stack	stack_b;

// 	if (create_stack(&stack_a, 10))
// 		return (1);
// 	if (create_stack(&stack_b, 10))
// 		return (2);
// 	for (int i = 0; i < 10; i++)
// 		add_item(&stack_a, i);

// 	printf("\n");

// 	// run ops here
// 	pb(&stack_a, &stack_b);
// 	pb(&stack_a, &stack_b);
// 	pb(&stack_a, &stack_b);
// 	pb(&stack_a, &stack_b);
// 	// pb(&stack_a, &stack_b);
// 	// ra(&stack_a);
// 	// pb(&stack_a, &stack_b);
// 	// rb(&stack_b);
// 	// rb(&stack_b);
// 	// pb(&stack_b, &stack_a);


// 	print_indices();
// 	print_stacks(&stack_a, &stack_b);

// 	return (0);
// }
