/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_circular_doubly_lst.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:43:07 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/11 14:11:51 by kchiang          ###   ########.fr       */
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
	new->index = 0;
	new->previous = new;
	new->next = new;
	return (new);
}

void	*ps_lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	last = (*lst)->previous;
	last->next = new;
	new->next = *lst;
	new->previous = last;
	(*lst)->previous = new;
	*lst = new;
	return ;
}

void	*ps_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	last = (*lst)->previous;
	last->next = new;
	new->next = *lst;
	new->previous = last;
	(*lst)->previous = new;
	return ;
}

void	ps_lstclear(t_stack **lst)
{
	t_stack	*junk;
	t_stack	*first;

	if (!lst)
		return ;
	first = *lst;
	junk = *lst;
	*lst = (*lst)->next;
	free(junk);
	while (*lst != first)
	{
		junk = *lst;
		*lst = (*lst)->next;
		free(junk);
	}
	return ;
}

size_t	ps_lstsize(t_stack **lst)
{
	size_t	size;
	t_stack	*first;

	if (!lst || !(*lst))
		return (0);
	size = 1;
	first = *lst;
	*lst = (*lst)->next;
	while (*lst != first)
	{
		size++;
		*lst = (*lst)->next;
	}
	return (size);
}
