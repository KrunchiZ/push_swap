/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:59:16 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 16:13:12 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_get_next_index(t_stack *b, index_a)
{
	t_stack	*prev;
	t_stack	*next;
	t_stack	*first;

	prev = b->previous;
	next = b->next;
	first = b;
	if (b->index < prev->index && b->index > next->index)
		return (b->index);
	b = b->next;
	while (b != first)
	{
		if (b->index < prev->index && b->index > next->index)
			return (b->index);
		b = b->next;
	}
	return (b->index);
}

void	ps_enhanced_insertion_sort(t_vars *set)
{
	int		index_a;
	int		index_b;
	size_t	size;

	size = set->args_size;
	ps_exec_push(set, PB);
	ps_exec_push(set, PB);
	if (ps_is_sorted(set->b))
		ps_exec_swap(set, SB);
	while (size > 3)
	{
		index_a = ps_get_fastest_index(set);
		index_b = ps_get_next_index(set->b, index_a);
		ps_ab_to_top(set, index_a);
		if (ps_is_sorted(set->a))
			break ;
		ps_exec_push(set, PB);
		size--;
	}
	ps_sort_three(set);
}
