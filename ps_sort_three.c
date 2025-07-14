/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:50:27 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/14 20:56:33 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_min_at_top(t_stack *a);
static int	ps_min_in_middle(t_stack *a);

void	ps_sort_three(t_stack **a)
{
	if (ps_min_at_top(*a))
		;
	else if (ps_min_in_middle(*a))
		;
	else
		;
	return ;
}

static int	ps_min_at_top(t_stack *a)
{
	t_stack	*last;
	t_stack	*sec;

	prev = a->previous;
	next = a->next;
	return (a->index < last->index && a->index < sec->index);
}

static int	ps_min_in_middle(t_stack *a)
{
	t_stack	*last;
	t_stack	*sec;

	prev = a->previous;
	next = a->next;
	return (sec->index < a->index && sec->index < last->index);
}
