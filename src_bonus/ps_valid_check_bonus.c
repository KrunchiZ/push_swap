/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_valid_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:58:55 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 20:32:10 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
#include "libft.h"
#include "push_swap.h"

static int	ps_args_not_digit(char **args);
static int	ps_args_has_dup(char **args);
static int	ps_args_not_int(char **args);

/* Function to check if arg parsed is digit, does not contain duplicate
 * and does not exceed the range of int type.
 * */
void	ps_valid_check(char **args)
{
	if (ps_args_not_digit(args) || ps_args_has_dup(args)
		|| ps_args_not_int(args))
	{
		ps_free_args(args);
		ps_error_abort();
	}
	return ;
}

/*
 * HELPER FUNCTIONS.
 * */
static int	ps_args_not_digit(char **args)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (args[i])
	{
		count = 0;
		j = 0;
		while (args[i][j])
		{
			if (!count && (args[i][j] == '+' || args[i][j] == '-'))
				j++;
			if (!ft_isdigit(args[i][j]))
				return (true);
			count++;
			if (count > 10)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static int	ps_args_has_dup(char **args)
{
	int		i;
	int		j;
	size_t	cmplen;

	cmplen = 11;
	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (!ft_strncmp(args[i], args[j], cmplen))
				return (true);
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static int	ps_args_not_int(char **args)
{
	t_llong	nb;

	while (*args)
	{
		nb = ft_atoll(*args);
		if (nb < INT_MIN || nb > INT_MAX)
			return (true);
		args++;
	}
	return (false);
}
