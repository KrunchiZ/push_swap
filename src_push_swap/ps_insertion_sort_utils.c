/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:26:54 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/17 17:48:08 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_find_next_index(t_stack *a, int b_index);
static int	ps_count_to_top(t_vars set, char src, int src_index, int dst_index);

/* Functions to find the index with the shortest move to push to dest stack.
 * */
void	ps_get_fastest_index(t_vars set, t_tracker *trkr, char src)
{
	int		current_count;
	int		next_index;
	t_stack	*b;

	b = set.b;
	trkr->src_index = b->index;
	trkr->dst_index = ps_find_next_index(set.a, trkr->src_index);
	trkr->count = ps_count_to_top(set, src, trkr->src_index, trkr->dst_index);
	b = b->next;
	while (b != set.b)
	{
		next_index = ps_find_next_index(set.a, b->index);
		current_count = ps_count_to_top(set, src, b->index, next_index);
		if (current_count < trkr->count)
		{
			trkr->src_index = b->index;
			trkr->count = current_count;
			trkr->dst_index = next_index;
		}
		b = b->next;
	}
	return ;
}

static int	ps_find_next_index(t_stack *a, int b_index)
{
	t_stack	*first;
	int		min_index;

	first = a;
	min_index = a->index;
	if (b_index > a->previous->index && b_index < a->index)
		return (a->index);
	a = a->next;
	while (a != first)
	{
		if (a->index < min_index)
			min_index = a->index;
		if (b_index > a->previous->index && b_index < a->index)
			return (a->index);
		a = a->next;
	}
	return (min_index);
}

static int	ps_count_to_top(t_vars set, char src, int src_index, int dst_index)
{
	t_counter	count;

	count = (t_counter){.src = src};
	ps_init_counter(&count, &set, src_index, dst_index);
	if (count.rr <= count.rrr && count.rr <= count.ra_rrb
		&& count.rr <= count.rra_rb)
		return (count.rr);
	else if (count.rrr && count.rrr <= count.ra_rrb
		&& count.rrr <= count.rra_rb)
		return (count.rrr);
	else if (count.ra_rrb <= count.rra_rb)
		return (count.ra_rrb);
	else
		return (count.rra_rb);
}
