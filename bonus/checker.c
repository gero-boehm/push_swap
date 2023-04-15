/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:45:48 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/15 10:41:01 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "get_next_line.h"
#include "libft.h"

static int	execute_ops(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_streq(line, "sa\n"))
		return (exec_swap(stack_a), 0);
	if (ft_streq(line, "sb\n"))
		return (exec_swap(stack_b), 0);
	if (ft_streq(line, "ss\n"))
		return (exec_swap(stack_a), exec_swap(stack_b), 0);
	if (ft_streq(line, "pa\n"))
		return (exec_push(stack_b, stack_a), 0);
	if (ft_streq(line, "pb\n"))
		return (exec_push(stack_a, stack_b), 0);
	if (ft_streq(line, "ra\n"))
		return (exec_rotate(stack_a), 0);
	if (ft_streq(line, "rb\n"))
		return (exec_rotate(stack_b), 0);
	if (ft_streq(line, "rr\n"))
		return (exec_rotate(stack_a), exec_rotate(stack_b), 0);
	if (ft_streq(line, "rra\n"))
		return (exec_rotate_reverse(stack_a), 0);
	if (ft_streq(line, "rrb\n"))
		return (exec_rotate_reverse(stack_b), 0);
	if (ft_streq(line, "rrr\n"))
		return (exec_rotate_reverse(stack_a), exec_rotate_reverse(stack_b), 0);
	return (1);
}

static int	evaluate_ops(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			return (0);
		if (execute_ops(line, stack_a, stack_b))
			return (free(line), 1);
		free(line);
	}
}

static void	evaluate_result(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size > 0 || !is_sorted(stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (0);
	if (init_stacks(++argv, &stack_a, &stack_b))
		return (1);
	if (evaluate_ops(&stack_a, &stack_b))
		return (free(stack_a.items), free(stack_b.items), error(), 2);
	evaluate_result(&stack_a, &stack_b);
	free(stack_a.items);
	free(stack_b.items);
	return (0);
}
