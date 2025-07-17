/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:03:56 by kchiang           #+#    #+#             */
/*   Updated: 2025/07/17 14:40:17 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>

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

/* Whitespaces delimiter for ft_split.
 * */
# define WHITESPACE	" \t\n\v\f\r"

/* Typedef for Circular Doubly Linked List Struct.
 * */
typedef struct s_stack
{
	int				nb;
	int				index;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

/* Typedef for Variable struct.
 * */
typedef struct s_vars
{
	char	**args;
	t_stack	*a;
	t_stack	*b;
	size_t	args_size;
}			t_vars;

/* Functions for Circular Doubly Linked List (lst).
 * */
t_stack	*ps_lstnew(int nb);
void	ps_lstadd_front(t_stack **lst, t_stack *new);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
void	ps_lstclear(t_stack **lst);
size_t	ps_lstsize(t_stack **lst);

/* Action functions.
 * */
void	ps_swap(t_stack **stack);
void	ps_swapswap(t_stack **a, t_stack **b);
void	ps_push(t_stack **dest, t_stack **src);
void	ps_rotate(t_stack **stack);
void	ps_dbl_rotate(t_stack **a, t_stack **b);
void	ps_revrotate(t_stack **stack);
void	ps_dbl_revrotate(t_stack **a, t_stack **b);
void	ps_exec_push(t_vars *set, char *action);
void	ps_exec_swap(t_vars *set, char *action);
void	ps_exec_rotate(t_vars *set, char *action);
void	ps_exec_dbl_rotate(t_vars *set, char *action);

/* Primary helper functions.
 * */
void	ps_error_abort(void);
void	ps_free_args(char **args);
void	ps_parse_arg(int argc, char **argv, t_vars *set);
void	ps_valid_check(char **args);
void	ps_init_stack_a(t_vars *set);
void	ps_sort_stack(t_vars *set);

/* Helper functions for ps_sort_stack.
 * */
int		ps_is_sorted(t_stack *stack);

#endif
