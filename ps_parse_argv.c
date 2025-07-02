/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:42:59 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/02 18:08:20 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char **ps_join_arg

void ps_parse_arg(int argc, char **argv, t_vars *set)
{
	if (argc == 2)
		set->arg = ft_split(argv[1], " \t\n\v\f\r");
	else
	{
		argv[1] = ps_join_arg(int argc, char **argv);
		if (argv[1] == NULL)
			ps_error_abort();
	}
	return ;
}
