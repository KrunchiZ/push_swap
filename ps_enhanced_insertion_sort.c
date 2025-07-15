/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_enhanced_insertion_sort.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:26:15 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/15 18:30:09 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_enhanced_insertion_sort(t_vars *set)
{
	ps_exec_push(set, PB);
	ps_exec_push(set, PB);
	if (ps_is_sorted(set->b))
		ps_exec_swap(set, SB);
}
