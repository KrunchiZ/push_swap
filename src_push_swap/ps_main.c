/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:20:51 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 02:58:47 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_vars	set;

	if (argc < 2)
		return (0);
	else
	{
		set = (t_vars){0};
		ps_parse_arg(argc, argv, &set);
		ps_valid_check(set.args);
		ps_init_stack_a(&set);
		ps_sort_stack(&set);
	}
	ps_lstclear(&(set.a));
	return (0);
}
