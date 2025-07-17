NAME		= push_swap
BONUS		= checker
LIBFT		= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
IFLAGS	= -Ilibft/include -Iinclude
PS_SRC	= \
		  ps_ab_to_top.c	ps_action_rotate.c	ps_action_swappush.c		\
		  ps_circular_doubly_lst.c	ps_error_abort.c	ps_exec_action.c	\
		  ps_free_args.c	ps_init_counter.c	ps_init_stack_a.c			\
		  ps_insertion_sort.c	ps_insertion_sort_utils.c	ps_is_sorted.c	\
		  ps_main.c	ps_parse_arg.c	ps_selection_sort.c	ps_sort_stack.c		\
		  ps_three_args_sort.c	ps_valid_check.c
BS_SRC	= \
		  checker.c	\
		  checker_utils.c

LIBFT_DIR	= libft/
PS_DIR		= src_push_swap/
BS_DIR		= src_bonus/

vpath %.c $(PS_DIR) $(BS_DIR)

GREEN	= \e[32m
CYAN	= \e[36m
WHITE	= \e[0m

.PHONY: all fclean clean re bonus

all: $(NAME)
bonus: $(BONUS)

$(NAME): $(PS_SRC) $(LIBFT)
	@$(CC) $(CFLAGS) $(IFLAGS) $(PS_DIR) $(LIBFT) -o push_swap
	@echo "Compiling $(GREEN)$(NAME)$(WHITE)..."

$(BONUS): $(BS_SRC) $(PS_SRC) $(LIBFT)
	@$(CC) $(CFLAGS) $(IFLAGS) $(BS_DIR) $(PS_DIR) $(LIBFT) -o checker
	@echo "Compiling $(GREEN)bonus$(WHITE)..."

$(LIBFT):
	@echo "Making $(GREEN)$(LIBFT)$(WHITE)..."
	@make -C $(LIBFT_DIR)
	@cp $(addprefix $(LIBFT_DIR), $(LIBFT)) $(LIBFT)

fclean: clean
	@rm -f $(NAME) $(BONUS) $(LIBFT)
	@echo "Removing program and library files..."

clean:
	@make -C $(LIBFT_DIR) clean

re: fclean all
