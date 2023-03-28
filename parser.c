/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:16:14 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/27 23:47:26 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"
#include "libft.h"

static int	does_arg_have_spaces(char *arg)
{
	while (*arg)
	{
		if (ft_iswhitespace(*arg))
			return (1);
		arg++;
	}
	return (0);
}

static int	is_invalid_number(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == 0)
		return (1);
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (1);
	}
	return (0);
}

static void	sanitize_spaces(char *str)
{
	while (*str)
	{
		if (ft_iswhitespace(*str))
			*str = ' ';
		str++;
	}
}

static int	is_arg_only_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

static int	split_group_into_values(char *group, t_array *arr)
{
	char	**split;

	if (ft_split2(group, ' ', &split))
		return (1);
	if (parse(arr, split))
		return (2);
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
