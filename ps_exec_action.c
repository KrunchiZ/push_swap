/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exec_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:34:57 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 00:47:05 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_exec_push(t_vars *set, char *action)
{
	if (!ft_strncmp(PA, action, 2))
	{
		ps_push(&(set->a), &(set->b));
		ft_putendl_fd(PA, STDOUT_FILENO);
	}
	else if (!ft_strncmp(PB, action, 2))
	{
		ps_push(&(set->b), &(set->a));
		ft_putendl_fd(PB, STDOUT_FILENO);
	}
	return ;
}

void	ps_exec_swap(t_stack **stack, char *action)
{
	ps_swap(stack);
	if (!ft_strncmp(SA, action, 2))
		ft_putendl_fd(SA, STDOUT_FILENO);
	if (!ft_strncmp(SB, action, 2))
		ft_putendl_fd(SB, STDOUT_FILENO);
}

void	ps_exec_rotate_a(t_stack **a, char *action)
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

void	ps_exec_rotate_b(t_stack **b, char *action)
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
