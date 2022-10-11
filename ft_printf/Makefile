NAME = libft_printf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
src/ft_putchar.c \
src/ft_puthexa.c \
src/ft_putnbr.c \
src/ft_putptr.c \
src/ft_putstr.c \
src/ft_len_functions.c

OBJS = $(SRCS:.c=.o)

RM = @rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $^

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean ${NAME}

.PHONY: all clean fclean re
