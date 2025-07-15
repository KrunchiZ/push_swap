/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:44:41 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 18:50:46 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_count_rotate(t_stack *a, int index);
static int	ps_count_revrotate(t_stack *a, int index);

/* Calculate the fastest rotate moves for given index.
 * */
void	ps_init_counter(t_counter *count, t_vars *set, int index_a, int index_b)
{
	count->ra = ps_count_rotate(set->a, index_a);
	count->rra = ps_count_revrotate(set->a, index_a);
	count->rb = ps_count_rotate(set->b, index_b);
	count->rrb = ps_count_revrotate(set->b, index_b);
	if (count->ra >= count->rb)
		count->rr = count->ra;
	else
		count->rr = count->rb;
	if (count->rra >= count ->rrb)
		count->rrr = count->rra;
	else
		count->rrr = count->rrb;
	count->ra_rrb = count->ra + count->rrb;
	count->rra_rb = count->rra + count->rb;
	return ;
}

static int	ps_count_rotate(t_stack *stack, int index)
{
	int	count;

	count = 0;
	while (stack && stack->index != index)
	{
		ps_rotate(&stack);
		count++;
	}
	return (count);
}

static int	ps_count_revrotate(t_stack *stack, int index)
{
	int	count;

	count = 0;
	while (stack && stack->index != index)
	{
		ps_revrotate(&stack);
		count++;
	}
	return (count);
}
