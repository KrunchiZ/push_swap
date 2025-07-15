/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:59:36 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 18:46:22 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			ps_insertion_sort(set);
	}
	return ;
}
