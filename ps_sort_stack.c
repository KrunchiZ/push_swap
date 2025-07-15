/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:59:36 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 16:30:53 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_is_sorted(t_stack *a);
static void	ps_sort_five(t_vars *set);

/* Sorting function that utilizes a modified version of selection sort
 * using min and max index.
 * */
void	ps_sort_stack(t_vars *set)
{
	if (!ps_is_sorted(set->a))
	{
		if (set->args_size <= 5)
			ps_selection_sort(set);
		else
			ps_enhanced_insertion_sort(set);
	}
	return ;
}

static int	ps_is_sorted(t_stack *stack)
{
	t_stack	*last;
	t_stack	*next;

	last = stack->previous;
	while (stack != last)
	{
		next = stack->next;
		if (stack->index > next->index)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static void	ps_selection_sort(t_vars *set)
{
	int		index_a;
	int		index_b;
	size_t	size;

	index_a = 0;
	size = set->args_size;
	while (size > 3)
	{
		index_b = index_a - 1;
		ps_ab_to_top(set, index_a, index_b);
		if (ps_is_sorted(set->a))
			break ;
		ps_exec_push(set, PB);
		index_a++;
		size--;
	}
	ps_sort_three(set);
	while (size++ < set->args_size)
		ps_exec_push(set, PA);
	return ;
}
