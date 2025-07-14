/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:26:25 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/11 14:34:43 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_sort_index(t_stack *stack);

void	ps_init_stack_a(t_vars *set)
{
	char	**args;
	t_stack	*stack;
	t_stack	*new_node;

	args = set->args;
	stack = set->a;
	while (*args)
	{
		new_node = ps_lstnew(ft_atoi(*args));
		if (!new)
		{
			ps_free_args(set->args);
			ps_lstclear(&stack);
			ps_error_abort();
		}
		if (stack == 0)
			stack == new_node;
		else
			ps_lstadd_back(&stack, new_node);
		ps_sort_index(stack);
		args++;
	}
	set->a = stack;
	ps_free_args(set->args);
	return ;
}

static void	ps_sort_index(t_stack *stack)
{
	t_stack	*last;

	last = stack->previous;
	while (stack != last)
	{
		if (last->nb > stack->nb)
			last->index++;
		else if (last->nb < stack->nb)
			stack->index++;
		stack = stack->next;
	}
	return ;
}
