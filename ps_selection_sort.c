/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:50:27 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/16 14:54:33 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Selection sort for 5 or less arguments.
 * */
void	ps_selection_sort(t_vars *set)
{
	int		index_a;
	int		index_b;
	size_t	size;

	index_a = 0;
	size = set->args_size;
	while (size > 3)
	{
		index_b = index_a - 1;
		ps_ab_to_top(set, index_a, index_b);
		if (ps_is_sorted(set->a))
			break ;
		ps_exec_push(set, PB);
		index_a++;
		size--;
	}
	if (size == 3)
		ps_three_args_sort(set);
	while (size++ < set->args_size)
		ps_exec_push(set, PA);
	return ;
}
