NAME		= push_swap
BONUS		= checker
LIBFT		= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
IFLAGS	= -Ilibft/include -Iinclude

PS_MAIN = \
		  ps_main.c
PS_SRC	= \
		  ps_ab_to_top.c			ps_action_rotate.c	ps_action_swappush.c	\
		  ps_circular_doubly_lst.c	ps_error_abort.c	ps_exec_action.c		\
		  ps_free_args.c			ps_init_counter.c	ps_init_stack_a.c		\
		  ps_is_sorted.c			ps_parse_arg.c		ps_selection_sort.c		\
		  ps_three_args_sort.c		ps_sort_stack.c		ps_valid_check.c		\
		  ps_insertion_sort.c		ps_insertion_sort_utils.c
BS_SRC	= \
		  checker_bonus.c	checker_utils_bonus.c	ps_action_rotate_bonus.c		\
		  ps_action_swappush_bonus.c				ps_circular_doubly_lst_bonus.c	\
		  ps_error_abort_bonus.c	ps_free_args_bonus.c	ps_init_stack_a_bonus.c	\
		  ps_is_sorted_bonus.c		ps_parse_arg_bonus.c	ps_valid_check_bonus.c

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

$(NAME): $(PS_SRC) $(PS_MAIN) $(LIBFT)
	@$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@
	@echo "Compiling $(GREEN)$(NAME)$(WHITE)..."

$(BONUS): $(BS_SRC) $(PS_SRC) $(LIBFT)
	@$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@
	@echo "Compiling $(GREEN)bonus$(WHITE)..."

$(LIBFT):
	@echo "Making $(GREEN)$(LIBFT)$(WHITE)..."
	@make -C $(LIBFT_DIR)
	@cp $(addprefix $(LIBFT_DIR), $(LIBFT)) $(LIBFT)

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@echo "Removing program files..."

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(LIBFT) $(LIBFT_DIR)/$(LIBFT)
	@echo "Removing $(GREEN)$(LIBFT)$(WHITE)..."

re: fclean all
