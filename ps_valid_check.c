/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_valid_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:58:55 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/09 20:02:17 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_args_not_digit(const char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			while (args[i][j] == '+' || args[i][j] == '-')
				j++;
			if (!ft_isdigit(args[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ps_args_has_dup(const char **args)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	while (args[i])
	{
		len = ft_strlen(args[i]);
		j = i + 1;
		while (args[j])
		{
			if (!ft_strncmp(args[i], args[j], len))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ps_args_not_int(const char **args)
{
	long long	nb;

	while (*args)
	{
		//atoi to check the number range of args
	}
}

static void	ps_free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	return ;
}

void	ps_valid_check(char **args)
{
	if (ps_args_not_digit(args) || ps_args_has_dup(args)
		|| ps_args_not_int(args))
	{
		ps_free_args(set->args);
		ps_error_abort();
	}
	return ;
}
