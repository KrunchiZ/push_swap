/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:50:27 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/17 02:39:44 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_get_min_index(t_stack *stack);

/* Selection sort for 5 or less arguments.
 * */
void	ps_selection_sort(t_vars *set)
{
	t_tracker	tracker;
	char		src;
	size_t		size;

	src = 'a';
	size = 5;
	tracker.dst_index = -1;
	while (size > 3)
	{
		tracker.src_index = ps_get_min_index(set->a);
		if (set->b)
			tracker.dst_index = (set->b)->index;
		ps_ab_to_top(set, src, tracker);
		if (ps_is_sorted(set->a))
			break ;
		ps_exec_push(set, PB);
		size--;
	}
	if (size == 3)
		ps_three_args_sort(set);
	while (size++ < 5)
		ps_exec_push(set, PA);
	return ;
}

static int	ps_get_min_index(t_stack *stack)
{
	int		min;
	t_stack	*first;

	min = stack->index;
	first = stack;
	stack = stack->next;
	while (stack != first)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}
