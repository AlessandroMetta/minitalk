CC = gcc -Wall -Wextra -Werror

CFLAGS =	-Wall -Wextra -Werror

NAME = utils.a

SRCS =	srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_putnbr.c \
		srcs/ft_atoi.c \
		srcs/ft_isspace.c \
		srcs/ft_isdigit.c \
		srcs/ft_putendl.c \
		srcs/ft_realloc.c \

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