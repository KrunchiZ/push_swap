/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:17:16 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/16 13:17:46 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_three(t_vars *set)
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
		ps_exec_rotate(set, RA);
	}
	else if (ps_min_in_middle(a) && a->index > last->index)
		ps_exec_rotate(set, RA);
	else if (ps_min_in_middle(a) && a->index < last->index)
		ps_exec_swap(set, SA);
	else if (a->index > sec->index)
	{
		ps_exec_swap(set, SA);
		ps_exec_rotate(set, RRA);
	}
	else
		ps_exec_rotate(set, RRA);
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
