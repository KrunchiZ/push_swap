/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_a_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:24:30 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 00:42:30 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_count_ra(t_stack *a, int index);
static int	ps_count_rra(t_stack *a, int index);

/* Rotate the node with index to the top using RA or RRA, whichever
 * is faster, using ps_count_ra/rra to determine the number of moves.
 * */
void	ps_a_to_top(t_stack **a, int index)
{
	int	ra_count;
	int	rra_count;

	if ((*a)->index != index)
	{
		ra_count = ps_count_ra(*a, index);
		rra_count = ps_count_rra(*a, index);
		if (ra_count < rra_count)
			ps_exec_rotate_a(a, RA);
		else
			ps_exec_rotate_a(a, RRA);
	}
	return ;
}

static int	ps_count_ra(t_stack *a, int index)
{
	int	count;

	count = 0;
	while (a->index != index)
	{
		ps_rotate(&a);
		count++;
	}
	return (count);
}

static int	ps_count_rra(t_stack *a, int index)
{
	int	count;

	count = 0;
	while (a->index != index)
	{
		ps_revrotate(&a);
		count++;
	}
	return (count);
}
