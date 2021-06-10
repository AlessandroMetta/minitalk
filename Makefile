CC = gcc -Wall -Wextra -Werror

CFLAGS =	-Wall -Wextra -Werror

NAME_SERVER = server

NAME_CLIENT = client

SRCS_SERVER = server.c

SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

LIBFT =	libft/libft.a

all: $(NAME_SERVER)

$(NAME_SERVER): $(OBJS_SERVER)
				@make -C libft
				$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) $(LIBFT)

$(NAME_CLIENT): $(OBJS_CLIENT)
				@make -C libft
				$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(LIBFT)
				
clean:
		@make clean -C libft
		rm -f $(OBJS_SERVER)
		rm -f $(OBJS_CLIENT)

fclean:	clean
		@make fclean -C libft
		rm -f $(NAME_SERVER)
		rm -f $(NAME_CLIENT)

re:		fclean all

.PHONY:	clean fclean re all