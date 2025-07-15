/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ab_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:24:30 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 17:47:17 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_exec_rr_ra_rb(int ra, int rb);
static void	ps_exec_rrr_rra_rrb(int rra, int rrb);

/* Rotate the node with index to the top using RA or RRA, whichever
 * is faster, using ps_count_ra/rra to determine the number of moves.
 * */
void	ps_ab_to_top(t_vars *set, int index_a, int index_b)
{
	t_counter	count;
	t_stack		*a;

	a = set->a;
	if (a->index != index_a)
	{
		ps_init_counter(&count, index_a, index_b);
		if ((count.rr <= count.rrr) && (count.rr <= count.ra_rrb)
			&& (count.rr <= count.rra_rb))
			ps_exec_rr_ra_rb(count.ra, count,rb);
		else if ((count.rrr <= count.ra_rrb) && (count.rrr <= count.rra_rb))
			ps_exec_rrr_rra_rrb(count.rra, count.rrb);
		else if (count.ra_rrb <= count.rra_rb)
		{
		}// exec RA + RRB
		else
		{
		}// exec RRA + RB

	}
	return ;
}

static void	ps_exec_rr_ra_rb(int ra, int rb)
{
	while (ra-- > 0 && rb-- > 0)
		ps_exec_rotate(set, RR);
	while (ra-- > 0)
		ps_exec_rotate(set, RA);
	while (rb-- > 0)
		ps_exec_rotate(set, RB);
	return ;
}

static void	ps_exec_rrr_rra_rrb(int rra, int rrb)
{
	while (rra-- > 0 && rrb-- > 0)
		ps_exec_rotate(set, RRR);
	while (rra-- > 0)
		ps_exec_rotate(set, RRA);
	while (rrb-- > 0)
		ps_exec_rotate(set, RRB);
	return ;
}
