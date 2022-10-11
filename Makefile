NAME	= push_swap

CC		= gcc -g

CFLAGS	= -Wall -Wextra -Werror

SRC		= main.c \
		parse.c \
		init.c \
		moves_utils.c \
		moves.c \
		lst_utils.c \
		sort_utils.c \
		positions.c \
		sort.c \
		cost.c \

OBJ_DIR	= obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

$(OBJ_DIR)/%.o: %.c push_swap.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
	@make --no-print-directory -C ft_printf
	@$(CC) -o $(NAME) $(OBJ) -Lft_printf -lft_printf

all	: $(NAME)

clean	:
	@make --no-print-directory fclean -C ft_printf
	@rm -rf $(OBJ_DIR)/

fclean	: clean
	@rm -rf $(NAME)

re	: fclean
	@make --no-print-directory all

.PHONY	: all clean fclean re
