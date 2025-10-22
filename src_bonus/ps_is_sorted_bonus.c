/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_is_sorted_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:14:37 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 20:34:25 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "checker_bonus.h"

int	ps_is_sorted(t_stack *stack)
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
