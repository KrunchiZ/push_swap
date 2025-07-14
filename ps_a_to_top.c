/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_a_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:24:30 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/14 20:44:00 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_count_ra(t_stack *a, int index);
static int	ps_count_rra(t_stack *a, int index);
static void	ps_exec_rotate(t_stack **a, char *action);

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
			ps_exec_rotate(a, RA);
		else
			ps_exec_rotate(a, RRA);
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

static void	ps_exec_rotate(t_stack **a, char *action)
{
	if (!ft_strncmp(RA, action, 3))
	{
		while ((*a)->index != index)
		{
			ps_rotate(a);
			ft_putendl_fd(RA, STDOUT_FILENO);
		}
	}
	else if (!ft_strncmp(RRA, action, 3))
	{
		while ((*a)->index != index)
		{
			ps_revrotate(a);
			ft_putendl_fd(RRA, STDOUT_FILENO);
		}
	}
	return ;
}
