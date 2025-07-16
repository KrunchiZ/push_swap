/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:26:15 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/17 01:23:10 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_return_stack_b(t_vars *set, size_t size, char src);

/* Insertion sort for arguments that are more than 5.
 * Instead of just the top node in stack a, this variant finds
 * the cheapest/fastest node to push.
 * */
void	ps_insertion_sort(t_vars *set)
{
	char		src;
	size_t		size;
	t_tracker	tracker;

	src = 'a';
	ps_exec_push(set, PB);
	ps_exec_push(set, PB);
	if (ps_is_sorted(set->b))
		ps_exec_swap(set, SB);
	size = set->args_size - 2;
	while (size > 3)
	{
		ps_get_fastest_a_index(*set, &tracker, src);
		ps_ab_to_top(set, src, tracker);
		ps_exec_push(set, PB);
		if ((set->b)->index < (set->b)->next->index)
			ps_exec_rotate(set, RB);
		size--;
	}
	ps_three_args_sort(set);
	src = 'b';
	ps_return_stack_b(set, size, src);
	return ;
}

static void	ps_return_stack_b(t_vars *set, size_t size, char src)
{
	t_tracker	tracker;

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
