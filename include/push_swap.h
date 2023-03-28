/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:44:25 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/28 01:43:35 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "libft.h"

typedef struct s_item {
	int	value;
	int	order;
}	t_item;

typedef struct s_stack {
	t_item			*items;
	size_t			size;
	size_t			max_size;
	unsigned long	start;
	char			label;
}	t_stack;

int				parse(t_array *arr, char **args);

int				create_stack(t_stack *stack, size_t size, char label);
int				add_item(t_stack *stack, t_item item);
t_item			get_item_at(t_stack *stack, long index);
void			set_item_at(t_stack *stack, long index, t_item item);
unsigned long	normalize_index(t_stack *stack, long index);

void			exec_swap(t_stack *stack);
void			exec_push(t_stack *stack1, t_stack *stack2);
void			exec_rotate(t_stack *stack);
void			exec_rotate_reverse(t_stack *stack);

void			swap(t_stack *stack);
void			swap_both(t_stack *stack1, t_stack *stack2);
void			push(t_stack *stack1, t_stack *stack2);
void			rotate(t_stack *stack);
void			rotate_both(t_stack *stack1, t_stack *stack2);
void			rotate_reverse(t_stack *stack);
void			rotate_reverse_both(t_stack *stack1, t_stack *stack2);

int				is_sorted(t_stack *stack);
void			sort(t_stack *stack_a, t_stack *stack_b);

#endif
