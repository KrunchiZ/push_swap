/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_a_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:24:30 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 14:36:01 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_count_ra(t_stack *a, int index);
static int	ps_count_rra(t_stack *a, int index);

/* Rotate the node with index to the top using RA or RRA, whichever
 * is faster, using ps_count_ra/rra to determine the number of moves.
 * */
void	ps_a_to_top(t_vars *set, int index)
{
	int		ra_count;
	int		rra_count;
	t_stack	*a;

	a = set->a;
	if (a->index != index)
	{
		ra_count = ps_count_ra(a, index);
		rra_count = ps_count_rra(a, index);
		while (a->index != index)
		{
			if (ra_count <= rra_count)
				ps_exec_rotate_a(set, RA);
			else
				ps_exec_rotate_a(set, RRA);
			a = set->a;
		}
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
