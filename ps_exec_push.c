/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exec_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:34:57 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/14 20:35:12 by kchiang          ###   ########.fr       */
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
