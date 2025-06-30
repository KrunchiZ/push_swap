/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:03:56 by kchiang           #+#    #+#             */
/*   Updated: 2025/06/30 14:24:23 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/* Macros for action strings.
 * */
# define SA		"sa"
# define SB		"sb"
# define SS		"ss"
# define PA		"pa"
# define PB		"pb"
# define RA		"ra"
# define RB		"rb"
# define RR		"rr"
# define RRA	"rra"
# define RRB	"rrb"
# define RRR	"rrr"

/* Typedef for Circular Doubly Linked List Struct.
 * */
typedef struct s_stack
{
	int				nb;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

/* Functions for Circular Doubly Linked List (cdlst).
 * */
t_stack	*ft_cdlstnew(void *nb);
void	ft_cdlstadd_front(t_stack **cdlst, t_stack *new);
void	ft_cdlstadd_back(t_stack **cdlst, t_stack *new);
void	ft_cdlstdelone(t_stack *cdlst);
void	ft_cdlstclear(t_stack **cdlst);

#endif
