/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:02:44 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/17 15:02:45 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	create_stack(t_stack *stack, size_t size)
{
	if (ft_malloc2(size * sizeof(t_item), (void **) &stack->items))
		return (1);
	stack->size = 0;
	stack->max_size = size;
	stack->start = 0;
	return (0);
}

unsigned long	normalize_index(t_stack *stack, long index)
{
	return ((index + stack->start + stack->max_size) % stack->max_size);
}

int	add_item(t_stack *stack, t_item item)
{
	unsigned long	index;

	if (stack->size == stack->max_size)
		return (1);
	index = normalize_index(stack, stack->size++);
	stack->items[index] = item;
	return (0);
}

t_item	get_item_at(t_stack *stack, long index)
{
	index = normalize_index(stack, index);
	return (stack->items[index]);
}

void	set_item_at(t_stack *stack, long index, t_item item)
{
	index = normalize_index(stack, index);
	stack->items[index] = item;
}

void	print_stack(t_stack *stack)
{
	if (stack->size == 0)
	{
		printf("                    ");
		return ;
	}
	for (int i = 0; i < 10; i++)
	{
		if ((i >= stack->start && i <= stack->start + stack->size - 1) || (stack->start + stack->size > 10 && i <= normalize_index(stack, stack->size - 1)))
			printf("%d ", get_item_at(stack, i - stack->start));
		else
			printf("  ");
	}
}

void	print_indices()
{
	printf("\n");
	printf("\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", i);
	printf("    ");
	for (int i = 0; i < 10; i++)
		printf("%d ", i);
	printf("\n");
}

void	print_stacks(t_stack *stack1, t_stack *stack2)
{
	print_stack(stack1);
	printf("    ");
	print_stack(stack2);
	printf("\n");
	printf("\n");
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
