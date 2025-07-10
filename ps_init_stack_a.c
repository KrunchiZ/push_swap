/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:26:25 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/10 20:09:45 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_simplify_a(t_vars *set);

void	ps_init_stack_a(t_vars *set)
{
	char	**args;
	t_stack	*a;
	t_stack	*new_node;

	args = set->args;
	a = set->a;
	while (*args)
	{
		new_node = ps_lstnew(ft_atoi(*args));
		if (!new)
		{
			ps_free_args(set->args);
			ps_lstclear(&a);
			ps_error_abort();
		}
		if (a == 0)
			a == new_node;
		else
			ps_lstadd_back(&a, new_node);
		args++;
	}
	set->a = a;
	ps_simplify_a(set);
	return (ps_free_args(set->args));
}

static void	ps_simplify_a(t_vars *set)
{
	//simplify the numbers to basic index numbers.
	//how-to:
	// -use a int array of args_size, parse all the number in.
	// -sort the array then assign the index to their respective nb in stack a.
}
