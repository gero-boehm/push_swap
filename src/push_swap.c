/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:33:11 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/15 10:39:22 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (0);
	if (init_stacks(++argv, &stack_a, &stack_b))
		return (1);
	if (!is_sorted(&stack_a))
		sort(&stack_a, &stack_b);
	free(stack_a.items);
	free(stack_b.items);
	return (0);
}
