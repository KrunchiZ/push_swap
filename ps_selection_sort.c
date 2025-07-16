/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:50:27 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/16 23:03:11 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Selection sort for 5 or less arguments.
 * */
void	ps_selection_sort(t_vars *set)
{
	t_tracker	tracker;
	char		src;
	size_t		size;

	tracker.src_index = 0;
	src = 'a';
	size = set->args_size;
	while (size > 3)
	{
		tracker.dst_index = tracker.src_index - 1;
		ps_ab_to_top(set, src, tracker);
		if (ps_is_sorted(set->a))
			break ;
		ps_exec_push(set, PB);
		if ((set->b)->index < (set->b)->next->index)
			ps_exec_rotate(set, RB);
		tracker.src_index++;
		size--;
	}
	if (size == 3)
		ps_three_args_sort(set);
	while (size++ < set->args_size)
		ps_exec_push(set, PA);
	return ;
}
