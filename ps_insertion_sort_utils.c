/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:26:54 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/16 22:33:40 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_find_next_index(t_stack *stack, int src_index);
static int	ps_count_to_top(t_vars set, int src_index, int dst_index);

/* Functions to find the index with the shortest move to push to dest stack.
 * */
void	ps_get_fastest_a_index(t_vars set, t_tracker *trkr, char src)
{
	int		current_count;
	int		next_index;
	t_stack	*first;

	trkr->src_index = (set.a)->index;
	trkr->dst_index = ps_find_next_index(set.b, trkr->src_index);
	trkr->count = ps_count_to_top(set, src, trkr->src_index, trkr->dst_index);
	first = set.a;
	set.a = (set.a)->next;
	while (set.a != first)
	{
		next_index = ps_find_next_index(set.b, (set.a)->index);
		current_count = ps_count_to_top(set, src, (set.a)->index, next_index);
		if (current_count < trkr->count)
		{
			trkr->src_index = (set.a)->index;
			trkr->count = current_count;
			trkr->dst_index = next_index;
		}
		set.a = (set.a)->next;
	}
	return ;
}

void	ps_get_fastest_b_index(t_vars set, t_tracker *trkr, char src)
{
	int		current_count;
	int		next_index;
	t_stack	*first;

	trkr->src_index = (set.b)->index;
	trkr->dst_index = ps_find_next_index(set.a, trkr->src_index);
	trkr->count = ps_count_to_top(set, src, trkr->src_index, trkr->dst_index);
	first = set.b;
	set.b = (set.b)->next;
	while (set.b != first)
	{
		next_index = ps_find_next_index(set.a, (set.b)->index);
		current_count = ps_count_to_top(set, src, (set.b)->index, next_index);
		if (current_count < trkr->count)
		{
			trkr->src_index = (set.b)->index;
			trkr->count = current_count;
			trkr->dst_index = next_index;
		}
		set.b = (set.b)->next;
	}
	return ;
}

static int	ps_find_next_index(t_stack *stack, int src_index)
{
	t_stack	*first;

	first = stack;
	if (src_index < stack->previous->index && src_index > stack->index)
		return (stack->index);
	stack = stack->next;
	while (stack != first)
	{
		if (src_index < stack->previous->index && src_index > stack->index)
			return (stack->index);
		stack = stack->next;
	}
	return (first->index);
}

static int	ps_count_to_top(t_vars set, char src, int src_index, int dst_index)
{
	t_counter	count;

	count = (t_counter){.src = src};
	ps_init_counter(&count, &set, src_index, dst_index);
	if (count.rr && (count.rr <= count.rrr)
		&& (count.rr <= count.ra_rrb) && (count.rr <= count.rra_rb))
		return (count.rr);
	else if (count.rrr && (count.rrr <= count.ra_rrb)
		&& (count.rrr <= count.rra_rb))
		return (count.rrr);
	else if (count.ra_rrb <= count.rra_rb)
		return (count.ra_rrb);
	else
		return (count.rra_rb);
}
