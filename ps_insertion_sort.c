/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:26:15 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/16 13:18:16 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_get_fastest_index(t_vars set, t_tracker *trkr);
static int	ps_find_next_index(t_stack *stack, int index_a);
static int	ps_count_to_top(t_vars set, int index_a, int index_b);

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
	ps_get_fastest_index(*set, &tracker);
	while (size > 3)
	{
		ps_ab_to_top(set, tracker.src_index, tracker.dst_index);
		ps_exec_push(set, PB);
		ps_get_fastest_index(*set, &tracker);
		size--;
	}
	ps_sort_three(set);
}

static void	ps_get_fastest_index(t_vars set, t_tracker *trkr)
{
	int			current_count;
	int			next_b_index;
	t_stack		*first;

	trkr->src_index = (set.a)->index;
	trkr->dst_index = ps_find_next_index(set.b, trkr->src_index);
	trkr->count = ps_count_to_top(set, trkr->src_index, trkr->dst_index);
	first = set.a;
	set.a = (set.a)->next;
	while (set.a != first)
	{
		new_b_index = ps_find_next_index(set.b, (set.a)->index);
		current_count = ps_count_to_top(set, (set.a)->index, new_b_index);
		if (current_count < track->count)
		{
			trkr->src_index = (set.a)->index;
			trkr->count = current_count;
			trkr->dst_index = new_b_index;
		}
		set.a = (set.a)->next;
	}
	return ;
}

static int	ps_find_next_index(t_stack *stack, int index_a)
{
	t_stack	*first;

	first = stack;
	if (index_a < (stack->previous)->index && index_a > stack->index)
		return (stack->index);
	stack = stack->next;
	while (stack != first)
	{
		if (index_a < (stack->previous)->index && index_a > stack->index)
			return (stack->index);
		stack = stack->next;
	}
	return (first->index);
}

static int	ps_count_to_top(t_vars set, int index_a, int index_b)
{
	t_counter	count;
	t_stack		*a;

	a = set->a;
	count = (t_counter){0};
	ps_init_counter(&count, set, index_a, index_b);
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
