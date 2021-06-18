CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = bonus/srcs
UTILS_DIR = utils

GREEN = '\033[0;32m'
WHITE = '\033[0;37m'

OBJS_DIR = objs

SERVER_SRCS_FILES = server_bonus.c
CLIENT_SRCS_FILES = client_bonus.c
UTILS_FILES = utils1.c utils2.c utils_bonus.c

OBJS_SERVER = $(SERVER_SRCS_FILES:%.c=%.o)
OBJS_CLIENT = $(CLIENT_SRCS_FILES:%.c=%.o)
OBJS_UTILS = $(UTILS_FILES:%.c=%.o)

SERVER_SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(SERVER_SRCS_FILES))
CLIENT_SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(CLIENT_SRCS_FILES))
UTILS_PATH = $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))
SRCS_PATH = $(SERVER_SRCS_PATH) $(CLIENT_SRCS_PATH) $(UTILS_PATH)

OBJS_SERVER_FILES = $(addprefix $(OBJS_DIR)/, $(OBJS_SERVER))
OBJS_CLIENT_FILES = $(addprefix $(OBJS_DIR)/, $(OBJS_CLIENT))
OBJS_UTILS_FILES = $(addprefix $(OBJS_DIR)/, $(OBJS_UTILS))
OBJS = $(OBJS_SERVER_FILES) $(OBJS_CLIENT_FILES) $(OBJS_UTILS_FILES)

all : $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS_SERVER_FILES) $(OBJS_UTILS_FILES) -o server
		@echo $(GREEN)[server executable created]$(WHITE)
		@$(CC) $(CFLAGS) $(OBJS_CLIENT_FILES) $(OBJS_UTILS_FILES) -o client
		@echo $(GREEN)[client executable created]$(WHITE)
		@echo $(GREEN)[DONE]$(WHITE)

$(OBJS) : $(SRCS_PATH)
			@$(CC) $(CFLAGS) $(SRCS_PATH) -c
			@mv *.o objs
			@echo $(GREEN)[objects file compiled]$(WHITE)

bonus : all 

clean:
		@rm -f $(OBJS)
		@echo $(GREEN)[objects files deleted]$(WHITE)

fclean:	clean
		@rm -f server
		@rm -f client
		@echo $(GREEN)[executable files deleted]$(WHITE)

re:		fclean all

.PHONY:	clean fclean re all