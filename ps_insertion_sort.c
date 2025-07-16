/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:26:15 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/16 19:01:37 by kchiang          ###   ########.fr       */
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
	int			index_a;
	size_t		size;
	t_tracker	tracker;

	size = set->args_size;
	ps_exec_push(set, PB);
	ps_exec_push(set, PB);
	if (ps_is_sorted(set->b))
		ps_exec_swap(set, SB);
	while (size > 3)
	{
		ps_get_fastest_a_index(*set, &tracker);
		ps_ab_to_top(set, tracker.src_index, tracker.dst_index);
		ps_exec_push(set, PB);
		size--;
	}
	ps_three_args_sort(set);
	ps_return_stack_b(set, size);
	ps_sort_stack_a(set);
	return ;
}

static void	ps_return_stack_b(t_vars *set, size_t size)
{
	t_tracker	tracker;

	while (size < set->args_size)
	{
		ps_get_fastest_b_index(*set, &tracker);
		ps_ab_to_top(set, tracker.src_index, tracker.dst_index);
		ps_exec_push(set, PA);
		size++;
	}
	return ;
}
