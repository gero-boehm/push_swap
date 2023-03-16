/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:16:14 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/16 16:27:25 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "ft_printf.h"

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

int	parse(t_array *arr, char **args)
{
	long	value;
	char	**split;

	while (*args != NULL)
	{
		if (does_arg_have_spaces(*args))
		{
			sanitize_spaces(*args);
			if (ft_split2(*args, ' ', &split))
				return (1);
			if (parse(arr, split))
				return (2);
			args++;
			continue ;
		}
		if (is_invalid_number(*args))
			return (3);
		value = ft_atol(*args);
		if (value > INT_MAX)
			return (4);
		add_element(arr, &value);
		args++;
	}
	return (0);
}

void error(void)
{
	ft_fdprintf(2, "Error\n");
}

int	main(int argc, char **argv)
{
	t_array	values;
	long	value;

	if (create_array(&values, sizeof(int)))
		return (error(), 1);
	argv++;
	if (parse(&values, argv))
		return (error(), 2);

	for (int i = 0; i < values.size; i++)
	{
		int value = *(int *) get_element_at(&values, i);
		ft_printf("%d\n", value);
	}

}
