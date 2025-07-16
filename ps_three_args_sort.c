/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_three_args_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:17:16 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/16 15:29:29 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sorting algorithm for three arguments stack.
 * */
void	ps_three_args_sort(t_vars *set)
{
	t_stack	*a;

	a = set->a;
	if (a->next->index < a->index && a->next->index < a->previous->index)
		ps_exec_rotate(set, RRA);
	else if (a->index < a->previous->index && a->index < a->next->index)
		ps_exec_rotate(set, RA);
	if (a->index > a->next->index)
		ps_exec_swap(set, SA);
	return ;
}
	
