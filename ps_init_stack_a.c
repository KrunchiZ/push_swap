/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:26:25 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/11 13:33:15 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_simplify_a(t_vars *set);
static void	ps_sort_int_tab(int *array, size_t size);

void	ps_init_stack_a(t_vars *set)
{
	char	**args;
	t_stack	*a;
	t_stack	*new_node;

	args = set->args;
	a = set->a;
	while (*args)
	{
		new_node = ps_lstnew(ft_atoi(*args));
		if (!new)
		{
			ps_free_args(set->args);
			ps_lstclear(&a);
			ps_error_abort();
		}
		if (a == 0)
			a == new_node;
		else
			ps_lstadd_back(&a, new_node);
		args++;
	}
	set->a = a;
	ps_simplify_a(set);
	ps_free_args(set->args);
}

static void	ps_simplify_a(t_vars *set)
{
	int		*tab;
	size_t	i;
	t_stack	*tmp;

	tab = malloc(sizeof(int) * set->args_size);
	if (!tab)
	{
		ps_free_args(set->args);
		ps_lstclear(&a);
		ps_error_abort();
	}
	tmp = set->a;
	i = 0;
	while (i < set->args_size)
	{
		tab[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	ps_sort_int_tab(tab, set->args_size);
}

static void	ps_sort_int_tab(int *tab, size_t size)
{
	int		i;
	int		temp;
	size_t	round;

	round = 0;
	while (round < size)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		round++;
	}
}
