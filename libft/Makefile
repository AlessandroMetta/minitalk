CC = gcc -Wall -Wextra -Werror

CFLAGS =	-Wall -Wextra -Werror

NAME = libft.a

SRCS =	srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_putnbr.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all