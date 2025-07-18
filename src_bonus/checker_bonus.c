/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:20:51 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/18 16:39:59 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ps_print_message(t_vars *set);

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
		ps_print_message(&set);
	}
	ps_lstclear(&(set.a));
	return (0);
}

static void	ps_print_message(t_vars *set)
{
	if (ps_is_sorted(set->a) && ps_lstsize(&(set->b)) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return ;
}
