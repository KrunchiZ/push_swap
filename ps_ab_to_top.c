/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ab_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:24:30 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 20:07:00 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_exec_rr_ra_rb(t_vars *set, int ra, int rb);
static void	ps_exec_rrr_rra_rrb(t_vars *set, int rra, int rrb);
static void	ps_exec_ra_rrb(t_vars *set, int ra, int rrb);
static void	ps_exec_rra_rb(t_vars *set, int rra, int rb);

/* Rotate the node with index to the top using the fastest way.
 * Enhanced insertion sort / Turk sort.
 * */
void	ps_ab_to_top(t_vars *set, int index_a, int index_b)
{
	t_counter	count;
	t_stack		*a;

	a = set->a;
	count = (t_counter){0};
	if (a->index != index_a)
	{
		ps_init_counter(&count, set, index_a, index_b);
		if (count.rr && (count.rr <= count.rrr)
			&& (count.rr <= count.ra_rrb) && (count.rr <= count.rra_rb))
			ps_exec_rr_ra_rb(set, count.ra, count.rb);
		else if (count.rrr && (count.rrr <= count.ra_rrb)
				&& (count.rrr <= count.rra_rb))
			ps_exec_rrr_rra_rrb(set, count.rra, count.rrb);
		else if (count.ra_rrb <= count.rra_rb)
			ps_exec_ra_rrb(set, count.ra, count.rrb);
		else
			ps_exec_rra_rb(set, count.rra, count.rb);
	}
	return ;
}

static void	ps_exec_rr_ra_rb(t_vars *set, int ra, int rb)
{
	while (ra-- > 0 && rb-- > 0)
		ps_exec_dbl_rotate(set, RR);
	while (ra-- > 0)
		ps_exec_rotate(set, RA);
	while (rb-- > 0)
		ps_exec_rotate(set, RB);
	return ;
}

static void	ps_exec_rrr_rra_rrb(t_vars *set, int rra, int rrb)
{
	while (rra-- > 0 && rrb-- > 0)
		ps_exec_dbl_rotate(set, RRR);
	while (rra-- > 0)
		ps_exec_rotate(set, RRA);
	while (rrb-- > 0)
		ps_exec_rotate(set, RRB);
	return ;
}

static void	ps_exec_ra_rrb(t_vars *set, int ra, int rrb)
{
	while (ra-- > 0)
		ps_exec_rotate(set, RA);
	while (rrb-- > 0)
		ps_exec_rotate(set, RRB);
	return ;
}

static void	ps_exec_rra_rb(t_vars *set, int rra, int rb)
{
	while (rra-- > 0)
		ps_exec_rotate(set, RRA);
	while (rb-- > 0)
		ps_exec_rotate(set, RB);
	return ;
}
