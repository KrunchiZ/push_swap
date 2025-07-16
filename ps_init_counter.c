/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:44:41 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/16 19:55:08 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_count_rotate(t_stack *a, int index);
static int	ps_count_revrotate(t_stack *a, int index);

/* Calculate the fastest rotate moves for given index.
 * */
void	ps_init_counter(t_counter *count, t_vars *set
					, int src_index, int dst_index)
{
	if (count->src == 'a')
	{
		count->ra = ps_count_rotate(set->a, src_index);
		count->rra = ps_count_revrotate(set->a, src_index);
		count->rb = ps_count_rotate(set->b, dst_index);
		count->rrb = ps_count_revrotate(set->b, dst_index);
	}
	else if (count->src == 'b')
	{
		count->ra = ps_count_rotate(set->a, dst_index);
		count->rra = ps_count_revrotate(set->a, dst_index);
		count->rb = ps_count_rotate(set->b, src_index);
		count->rrb = ps_count_revrotate(set->b, src_index);
	}
	if (count->ra && count->rb && count->ra >= count->rb)
		count->rr = count->ra;
	else if (count->ra && count->rb && count->rb > count->ra)
		count->rr = count->rb;
	if (count->rra && count->rrb && count->rra >= count->rrb)
		count->rrr = count->rra;
	else if (count->rra && count->rrb)
		count->rrr = count->rrb;
	count->ra_rrb = count->ra + count->rrb;
	count->rra_rb = count->rra + count->rb;
	return ;
}

static int	ps_count_rotate(t_stack *stack, int index)
{
	int	count;

	count = 0;
	while (stack && index >= 0 && stack->index != index)
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
	while (stack && index >= 0 && stack->index != index)
	{
		ps_revrotate(&stack);
		count++;
	}
	return (count);
}
