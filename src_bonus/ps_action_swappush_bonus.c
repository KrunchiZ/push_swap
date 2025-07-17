/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action_swappush_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:37:26 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/17 15:03:43 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ps_swap(t_stack **stack)
{
	t_stack	*second;
	t_stack	*third;

	if (!stack || !(*stack) || (*stack)->next == *stack)
		return ;
	second = (*stack)->next;
	third = second->next;
	(*stack)->next = third;
	third->previous = *stack;
	ps_lstadd_front(stack, second);
	return ;
}

void	ps_swapswap(t_stack **a, t_stack **b)
{
	ps_swap(a);
	ps_swap(b);
	return ;
}

void	ps_push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;
	t_stack	*srclast;

	if (!src || !(*src))
		return ;
	tmp = *src;
	srclast = (*src)->previous;
	*src = (*src)->next;
	(*src)->previous = srclast;
	srclast->next = *src;
	ps_lstadd_front(dest, tmp);
	return ;
}
