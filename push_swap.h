/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:03:56 by kchiang           #+#    #+#             */
/*   Updated: 2025/06/30 17:31:07 by kchiang          ###   ########.fr       */
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
t_stack	*ps_lstnew(int nb);
void	ps_lstadd_front(t_stack **cdlst, t_stack *new);
void	ps_lstadd_back(t_stack **cdlst, t_stack *new);
void	ps_lstdelone(t_stack **cdlst);
void	ps_lstclear(t_stack **cdlst);

/* Action functions
 * */
void	ps_swap(t_stack **stack);
void	ps_swapswap(t_stack **a, t_stack **b);
void	ps_push(t_stack **dest, t_stack **src);
void	ps_rotate(t_stack **stack);
void	ps_dbl_rotate(t_stack **a, t_stack **b);
void	ps_revrotate(t_stack **stack);
void	ps_dbl_revrotate(t_stack **a, t_stack **b);

#endif
