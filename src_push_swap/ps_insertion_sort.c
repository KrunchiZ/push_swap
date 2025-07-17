/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:26:15 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/17 17:04:17 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_return_stack_b(t_vars *set, size_t size);

/* Insertion sort for arguments that are more than 5.
 * Instead of just the top node in stack a, this variant finds
 * the cheapest/fastest node to push.
 * */
void	ps_insertion_sort(t_vars *set)
{
	size_t		size;

	size = set->args_size;
	while (size > 5)
	{
		ps_exec_push(set, PB);
		if ((set->b)->index < (int)set->args_size / 2)
			ps_exec_rotate(set, RB);
		size--;
	}
	ps_selection_sort(set);
	ps_return_stack_b(set, size);
	return ;
}

static void	ps_return_stack_b(t_vars *set, size_t size)
{
	t_tracker	tracker;
	char		src;

	src = 'b';
	while (size < set->args_size)
	{
		ps_get_fastest_b_index(*set, &tracker, src);
		ps_ab_to_top(set, src, tracker);
		ps_exec_push(set, PA);
		size++;
	}
	src = 'a';
	tracker.src_index = 0;
	tracker.dst_index = tracker.src_index - 1;
	ps_ab_to_top(set, src, tracker);
	return ;
}
