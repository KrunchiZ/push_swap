/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:59:36 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/14 20:43:55 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_sort_five(t_vars *set);
static void	ps_sort_three(t_stack **a);
static int	ps_min_at_top(t_stack *a);
static int	ps_min_in_middle(t_stack *a);

/* Sorting function that utilizes a modified version of selection sort.
 * */
void	ps_sort_stack(t_vars *set)
{
	if (!ps_a_is_sorted(set->a))
	{
		if (set->args_size <= 5)
			ps_sort_five(set);
	}
}

static void	ps_sort_five(t_vars *set)
{
	int		index;
	size_t	size;

	index = 0;
	size = set->args_size
	while (size > 3)
	{
		ps_a_to_top(&(set->a), index);
		if (ps_a_is_sorted(set->a))
			break;
		ps_exec_push(set, PB);
		index++;
		size--;
	}
	ps_sort_three(&(set->a));
}

static void	ps_sort_three(t_stack **a)
{
	if (ps_min_at_top(*a))
		;
	else if (ps_min_in_middle(*a))
		;
}

static int	ps_min_at_top(t_stack *a)
{
	t_stack	*prev;
	t_stack	*next;

	prev = a->previous;
	next = a->next;
	if (a->index < prev->index && a->index < next->index)
		return (TRUE);
	return (FALSE)
}
