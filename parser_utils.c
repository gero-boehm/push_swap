/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:53:36 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/28 23:02:43 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	does_arg_have_spaces(char *arg)
{
	while (*arg)
	{
		if (ft_iswhitespace(*arg))
			return (1);
		arg++;
	}
	return (0);
}

int	is_invalid_number(char *str)
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

void	sanitize_spaces(char *str)
{
	while (*str)
	{
		if (ft_iswhitespace(*str))
			*str = ' ';
		str++;
	}
}

int	is_arg_only_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}
