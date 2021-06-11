CC = gcc -Wall -Wextra -Werror

CFLAGS =	-Wall -Wextra -Werror

NAME_SERVER = server

NAME_CLIENT = client

SRCS_SERVER =	minitalk/srcs/server.c \

SRCS_CLIENT = minitalk/srcs/client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

LIBFT =	utils/utils.a

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
				@make -C utils
				$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) $(LIBFT)

$(NAME_CLIENT): $(OBJS_CLIENT)
				@make -C utils
				$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(LIBFT)
				
clean:
		@make clean -C utils
		rm -f $(OBJS_SERVER)
		rm -f $(OBJS_CLIENT)

fclean:	clean
		@make fclean -C utils
		rm -f $(NAME_SERVER)
		rm -f $(NAME_CLIENT)

re:		fclean all

.PHONY:	clean fclean re all