/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:42:59 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/31 12:16:33 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		*ps_join_arg(int argc, char **argv);
static void		ps_empty_check(char *arg, char *argv);
static size_t	ps_count_args(char **argv);

/* Parse all "word" strings from argv into 
 * */
void	ps_parse_arg(int argc, char **argv, t_vars *set)
{
	char	*arg;

	if (argc == 2)
		set->args = ft_split(argv[1], WHITESPACE);
	else
	{
		arg = ps_join_arg(argc, argv);
		set->args = ft_split(arg, WHITESPACE);
		free(arg);
	}
	if (!set->args)
		ps_error_abort();
	set->args_size = ps_count_args(set->args);
	if (set->args_size == 0)
	{
		ps_free_args(set->args);
		ps_error_abort();
	}
	return ;
}

/*
 * HELPER FUNCTIONS
 * */
static char	*ps_join_arg(int argc, char **argv)
{
	char	*arg;
	char	*tmp;
	int		i;

	arg = ft_strdup(argv[1]);
	if (!arg)
		ps_error_abort();
	i = 2;
	while (i < argc)
	{
		ps_empty_check(arg, argv[i]);
		tmp = arg;
		arg = ft_strjoin(tmp, " ");
		free(tmp);
		if (!arg)
			ps_error_abort();
		tmp = arg;
		arg = ft_strjoin(tmp, argv[i]);
		free(tmp);
		if (!arg)
			ps_error_abort();
		i++;
	}
	return (arg);
}

static void	ps_empty_check(char *arg, char *argv)
{
	if (!(*arg) || !(*argv))
	{
		free(arg);
		ps_error_abort();
	}
	return ;
}

static size_t	ps_count_args(char **args)
{
	size_t	count;

	count = 0;
	while (*args++)
		count++;
	return (count);
}
