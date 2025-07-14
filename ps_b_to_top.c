/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:24:30 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 03:09:44 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_count_rb(t_stack *b, int index);
static int	ps_count_rrb(t_stack *b, int index);

/* Rotate the node with index to the top using RB or RRB, whichever
 * is faster, using ps_count_rb/rrb to determine the number of moves.
 * */
void	ps_b_to_top(t_vars *set, int index)
{
	int		rb_count;
	int		rrb_count;
	t_stack	*b;

	b = set->b;
	if (b->index != index)
	{
		rb_count = ps_count_rb(b, index);
		rrb_count = ps_count_rrb(b, index);
		while (b->index != index)
		{
			if (rb_count < rrb_count)
				ps_exec_rotate_b(set, RB);
			else
				ps_exec_rotate_b(set, RRB);
			b = set->b;
		}
	}
	return ;
}

static int	ps_count_rb(t_stack *b, int index)
{
	int	count;

	count = 0;
	while (b->index != index)
	{
		ps_rotate(&b);
		count++;
	}
	return (count);
}

static int	ps_count_rrb(t_stack *b, int index)
{
	int	count;

	count = 0;
	while (b->index != index)
	{
		ps_revrotate(&b);
		count++;
	}
	return (count);
}
