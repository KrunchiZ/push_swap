/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exec_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:34:57 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 18:00:27 by kchiang          ###   ########.fr       */
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

void	ps_exec_swap(t_vars *set, char *action)
{
	if (!ft_strncmp(SA, action, 2))
	{
		ps_swap(&(set->a));
		ft_putendl_fd(SA, STDOUT_FILENO);
	}
	if (!ft_strncmp(SB, action, 2))
	{
		ps_swap(&(set->b));
		ft_putendl_fd(SB, STDOUT_FILENO);
	}
	return ;
}

void	ps_exec_rotate(t_vars *set, char *action)
{
	if (!ft_strncmp(RA, action, 3))
	{
		ps_rotate(&(set->a));
		ft_putendl_fd(RA, STDOUT_FILENO);
	}
	else if (!ft_strncmp(RRA, action, 3))
	{
		ps_revrotate(&(set->a));
		ft_putendl_fd(RRA, STDOUT_FILENO);
	}
	else if (!ft_strncmp(RB, action, 3))
	{
		ps_rotate(&(set->b));
		ft_putendl_fd(RB, STDOUT_FILENO);
	}
	else if (!ft_strncmp(RRB, action, 3))
	{
		ps_revrotate(&(set->b));
		ft_putendl_fd(RRB, STDOUT_FILENO);
	}
	return ;
}

void	ps_exec_dbl_rotate(t_vars *set, char *action)
{
	if (!ft_strncmp(RR, action, 3))
	{
		ps_dbl_rotate(&(set->a), &(set->b));
		ft_putendl_fd(RR, STDOUT_FILENO);
	}
	else if (!ft_strncmp(RRR, action, 3))
	{
		ps_dbl_revrotate(&(set->a), &(set->b));
		ft_putendl_fd(RRR, STDOUT_FILENO);
	}
	return ;
}
