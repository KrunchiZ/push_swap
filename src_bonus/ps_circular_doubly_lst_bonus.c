/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_circular_doubly_lst_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:43:07 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 20:37:13 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "checker_bonus.h"

t_stack	*ps_lstnew(int nb)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->index = 0;
	new->previous = new;
	new->next = new;
	return (new);
}

void	ps_lstadd_front(t_stack **lst, t_stack *node)
{
	t_stack	*last;

	if (!lst || !node)
		return ;
	if (*lst)
	{
		last = (*lst)->previous;
		last->next = node;
		node->next = *lst;
		node->previous = last;
		(*lst)->previous = node;
		*lst = node;
	}
	else
	{
		node->previous = node;
		node->next = node;
		*lst = node;
	}
	return ;
}

void	ps_lstadd_back(t_stack **lst, t_stack *node)
{
	t_stack	*last;

	if (!lst || !node)
		return ;
	if (*lst)
	{
		last = (*lst)->previous;
		last->next = node;
		node->next = *lst;
		node->previous = last;
		(*lst)->previous = node;
	}
	else
	{
		node->previous = node;
		node->next = node;
		*lst = node;
	}
	return ;
}

void	ps_lstclear(t_stack **lst)
{
	t_stack	*junk;
	t_stack	*first;

	if (!lst || !(*lst))
		return ;
	first = *lst;
	junk = *lst;
	*lst = (*lst)->next;
	free(junk);
	junk = NULL;
	while (*lst != first)
	{
		junk = *lst;
		*lst = (*lst)->next;
		free(junk);
		junk = NULL;
	}
	*lst = NULL;
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
