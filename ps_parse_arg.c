/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:42:59 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/10 17:13:29 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ps_join_arg(int argc, char **argv);

/* Parse all "word" strings from argv into 
 * */
void	ps_parse_arg(int argc, char **argv, t_vars *set)
{
	char	*arg;

	if (argc == 2)
		set->args = ft_split(argv[1], WHITESPACE);
	else
	{
		arg = ps_join_arg(int argc, char **argv);
		set->args = ft_split(arg, WHITESPACE);
	}
	if (!set->args)
		ps_error_abort();
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
