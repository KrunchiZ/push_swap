/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:24:30 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/14 21:16:35 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_count_rb(t_stack *b, int index);
static int	ps_count_rrb(t_stack *b, int index);
static void	ps_exec_rotate(t_stack **b, char *action);

/* Rotate the node with index to the top using RB or RRB, whichever
 * is faster, using ps_count_rb/rrb to determine the number of moves.
 * */
void	ps_b_to_top(t_stack **b, int index)
{
	int	rb_count;
	int	rrb_count;

	if ((*b)->index != index)
	{
		rb_count = ps_count_rb(*b, index);
		rrb_count = ps_count_rrb(*b, index);
		if (rb_count < rrb_count)
			ps_exec_rotate(b, RB);
		else
			ps_exec_rotate(b, RRB);
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

static void	ps_exec_rotate(t_stack **b, char *action)
{
	if (!ft_strncmp(RB, action, 3))
	{
		while ((*b)->index != index)
		{
			ps_rotate(b);
			ft_putendl_fd(RB, STDOUT_FILENO);
		}
	}
	else if (!ft_strncmp(RRB, action, 3))
	{
		while ((*b)->index != index)
		{
			ps_revrotate(b);
			ft_putendl_fd(RRB, STDOUT_FILENO);
		}
	}
	return ;
}
