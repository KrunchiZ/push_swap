/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cdlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:43:07 by kchiang           #+#    #+#             */
/*   Updated: 2025/06/30 16:30:13 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstnew(int nb)
{
	t_stack	*new;

	new = ps_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->previous = new;
	new->next = new;
	return (new);
}

void	*ps_lstadd_front(t_stack **cdlst, t_stack *new)
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

void	*ps_lstadd_back(t_stack **cdlst, t_stack *new)
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

void	ps_lstdelone(t_stack **cdlst)
{
	t_stack	*prev;
	t_stack	*junk;

	if (!cdlst)
		return ;
	junk = *cdlst;
	prev = junk->previous;
	*cdlst = (*cdlst)->next;
	(*cdlst)->previous = prev;
	prev->next = *cdlst;
	free(junk);
	return ;
}

void	ps_lstclear(t_stack **cdlst)
{
	t_stack	*junk;
	t_stack	*first;

	if (!cdlst)
		return ;
	first = *cdlst;
	junk = *cdlst;
	*cdlst = (*cdlst)->next;
	free(junk);
	while (*cdlst != first)
	{
		junk = *cdlst;
		*cdlst = (*cdlst)->next;
		free(junk);
	}
	return ;
}
