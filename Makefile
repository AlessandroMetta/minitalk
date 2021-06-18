CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus
NAME_UTILS = utils

SERVER_SRCS = mandatory/srcs/server.c
CLIENT_SRCS = mandatory/srcs/client.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_SRCS_BONUS = bonus/srcs/server_bonus.c
CLIENT_SRCS_BONUS = bonus/srcs/client_bonus.c bonus/srcs/utils_bonus.c
SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

UTILS_SRCS = utils/utils1.c utils/utils2.c
UTILS_OBJS = $(UTILS_SRCS:.c=.o)

all: fclean $(NAME_UTILS) $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_UTILS) : $(UTILS_OBJS)
				@echo [utils compiled]

$(NAME_SERVER): $(SERVER_OBJS)
				@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SERVER_OBJS) $(UTILS_OBJS)
				@echo [server execute created]

$(NAME_CLIENT): $(CLIENT_OBJS)
				@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(CLIENT_OBJS) $(UTILS_OBJS)
				@echo [client execute created]

bonus : fclean $(NAME_UTILS) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(SERVER_OBJS_BONUS)
						@$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(SERVER_OBJS_BONUS) $(UTILS_OBJS)
						@echo [BONUS server execute created]
				
$(NAME_CLIENT_BONUS): $(CLIENT_OBJS_BONUS)
						@$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(CLIENT_OBJS_BONUS) $(UTILS_OBJS)
						@echo [BONUS client execute created]

clean:
		@rm -f $(SERVER_OBJS)
		@rm -f $(CLIENT_OBJS)
		@rm -f $(SERVER_OBJS_BONUS)
		@rm -f $(CLIENT_OBJS_BONUS)
		@rm -f $(UTILS_OBJS)

fclean:	clean
		@rm -f $(NAME_SERVER)
		@rm -f $(NAME_CLIENT)
		@rm -f $(NAME_SERVER_BONUS)
		@rm -f $(NAME_CLIENT_BONUS)

re:		fclean all

.PHONY:	clean fclean re all