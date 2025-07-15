/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:50:27 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 18:17:05 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_sort_three(t_vars *set);
static int	ps_min_at_top(t_stack *a);
static int	ps_min_in_middle(t_stack *a);

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
	ps_sort_three(set);
	while (size++ < set->args_size)
		ps_exec_push(set, PA);
	return ;
}

static void	ps_sort_three(t_vars *set)
{
	t_stack	*last;
	t_stack	*sec;
	t_stack	*a;

	a = set->a;
	last = a->previous;
	sec = a->next;
	if (ps_min_at_top(a))
	{
		ps_exec_swap(set, SA);
		ps_exec_rotate_a(set, RA);
	}
	else if (ps_min_in_middle(a) && a->index > last->index)
		ps_exec_rotate_a(set, RA);
	else if (ps_min_in_middle(a) && a->index < last->index)
		ps_exec_swap(set, SA);
	else if (a->index > sec->index)
	{
		ps_exec_swap(set, SA);
		ps_exec_rotate_a(set, RRA);
	}
	else
		ps_exec_rotate_a(set, RRA);
	set->a = a;
	return ;
}

static int	ps_min_at_top(t_stack *a)
{
	t_stack	*last;
	t_stack	*sec;

	last = a->previous;
	sec = a->next;
	return (a->index < last->index && a->index < sec->index);
}

static int	ps_min_in_middle(t_stack *a)
{
	t_stack	*last;
	t_stack	*sec;

	last = a->previous;
	sec = a->next;
	return (sec->index < a->index && sec->index < last->index);
}
