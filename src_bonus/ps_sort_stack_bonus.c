/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:18:13 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/18 20:47:50 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ps_action_is_invalid(char *action);
static void	ps_exec_action(t_vars *set, char *action);

void	ps_sort_stack(t_vars *set)
{
	set->action = get_next_line(STDIN_FILENO);
	while (set->action)
	{
		if (ps_action_is_invalid(set->action))
		{
			free(set->action);
			ps_lstclear(&(set->a));
			ps_lstclear(&(set->b));
			ps_error_abort();
		}
		ps_exec_action(set, set->action);
		free(set->action);
		if (set->b == set->a)
			set->b = NULL;
		set->action = get_next_line(STDIN_FILENO);
	}
	return ;
}

static int	ps_action_is_invalid(char *action)
{
	size_t	len;

	len = ft_strlen(action) - 1;
	if (len == 0 && *action == '\n')
		return (true);
	else if (len == 0)
		return (true);
	if (!ft_strncmp(PA, action, len) || !ft_strncmp(PB, action, len)
		|| !ft_strncmp(SA, action, len) || !ft_strncmp(SB, action, len)
		|| !ft_strncmp(RA, action, len) || !ft_strncmp(RRA, action, len)
		|| !ft_strncmp(RB, action, len) || !ft_strncmp(RRB, action, len)
		|| !ft_strncmp(RR, action, len) || !ft_strncmp(RRR, action, len)
		|| !ft_strncmp(SS, action, len))
		return (false);
	return (true);
}

static void	ps_exec_action(t_vars *set, char *action)
{
	size_t	len;

	len = ft_strlen(action) - 1;
	if (!ft_strncmp(PA, action, len))
		ps_push(&(set->a), &(set->b));
	else if (!ft_strncmp(PB, action, len))
		ps_push(&(set->b), &(set->a));
	else if (!ft_strncmp(SA, action, len))
		ps_swap(&(set->a));
	else if (!ft_strncmp(SB, action, len))
		ps_swap(&(set->b));
	else if (!ft_strncmp(SS, action, len))
		ps_swapswap(&(set->a), &(set->b));
	else if (!ft_strncmp(RA, action, len))
		ps_rotate(&(set->a));
	else if (!ft_strncmp(RRA, action, len))
		ps_revrotate(&(set->a));
	else if (!ft_strncmp(RB, action, len))
		ps_rotate(&(set->b));
	else if (!ft_strncmp(RRB, action, len))
		ps_revrotate(&(set->b));
	else if (!ft_strncmp(RR, action, len))
		ps_dbl_rotate(&(set->a), &(set->b));
	else if (!ft_strncmp(RRR, action, len))
		ps_dbl_revrotate(&(set->a), &(set->b));
}
