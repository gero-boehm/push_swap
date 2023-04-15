/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:16:14 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/28 23:02:49 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"
#include "libft.h"

static int	split_group_into_values(char *group, t_array *arr)
{
	char	**split;

	if (ft_split2(group, ' ', &split))
		return (1);
	if (parse(arr, split))
		return (ft_free2d((void **) split), 2);
	ft_free2d((void **) split);
	return (0);
}

static int	parse_value(char *arg, t_array *arr)
{
	long	value;

	if (is_invalid_number(arg))
		return (1);
	value = ft_atol(arg);
	if (value > INT_MAX || value < INT_MIN)
		return (2);
	if (add_element(arr, &value))
		return (3);
	return (0);
}

int	parse(t_array *arr, char **args)
{
	while (*args != NULL)
	{
		if (does_arg_have_spaces(*args))
		{
			sanitize_spaces(*args);
			if (is_arg_only_spaces(*args))
				return (1);
			if (split_group_into_values(*args, arr))
				return (2);
		}
		else if (parse_value(*args, arr))
			return (3);
		args++;
	}
	return (0);
}
