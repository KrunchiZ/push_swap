/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:43:07 by kchiang           #+#    #+#             */
/*   Updated: 2025/06/30 13:43:40 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_cdlstnew(void *nb)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->previous = new;
	new->next = new;
return (new);
}

t_stack	*ft_cdlstadd_front(t_stack **cdlst, t_stack *new)
{
	t_stack	*last;

	if (!cdlst || !new)
		return ;
	last = (*cdlst)->previous;
	last->next = new;
	new->next = *cdlst;
	new->previous = last;
	(*cdlst)->previous = new;
	*cdlst = new;
	return ;
}

t_stack	*ft_cdlstadd_back(t_stack **cdlst, t_stack *new)
{
	t_stack	*last;

	if (!cdlst || !new)
		return ;
	last = (*cdlst)->previous;
	last->next = new;
	new->next = *cdlst;
	new->previous = last;
	(*cdlst)->previous = new;
	return ;
}

void	ft_cdlstdelone(t_stack *cdlst)
{
	t_stack	*prev;
	t_stack	*junk;

	if (!cdlst)
		return ;
	junk = cdlst;
	prev = junk->previous;
	cdlst = cdlst->next;
	cdlst->previous = prev;
	prev->next = cdlst;
	free(junk);
	return ;
}
