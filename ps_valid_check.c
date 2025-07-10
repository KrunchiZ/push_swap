/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_valid_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:58:55 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/10 17:15:49 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_args_not_digit(const char **args);
static int	ps_args_has_dup(const char **args);
static int	ps_args_not_int(const char **args);

/* Function to check if arg parsed is digit, does not contain duplicate
 * and does not exceed the range of int type.
 * */
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

/*
 * HELPER FUNCTIONS.
 * */
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
	t_llong	nb;

	while (*args)
	{
		nb = ft_atoi(*args);
		if (nb < INT_MIN || nb > INT_MAX)
			return (1);
		args++;
	}
	return (0);
}
