/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action_rotate_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:20:04 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/17 15:03:34 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ps_rotate(t_stack **stack)
{
	*stack = (*stack)->next;
	return ;
}

void	ps_dbl_rotate(t_stack **a, t_stack **b)
{
	ps_rotate(a);
	ps_rotate(b);
	return ;
}

void	ps_revrotate(t_stack **stack)
{
	*stack = (*stack)->previous;
	return ;
}

void	ps_dbl_revrotate(t_stack **a, t_stack **b)
{
	ps_revrotate(a);
	ps_revrotate(b);
	return ;
}
