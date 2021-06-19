CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = .
OBJS_DIR = .
UTILS_DIR = utils/srcs

FONT_COLOR_GREEN = '\033[0;32m'
FONT_COLOR_WHITE = '\033[0;37m'

SERVER_SRCS_FILES = server.c
CLIENT_SRCS_FILES = client.c
UTILS_FILES = utils1.c utils2.c utils_bonus.c put_str_in_color.c

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

all:	$(OBJS)
		@$(CC) $(CFLAGS) $(OBJS_SERVER_FILES) $(OBJS_UTILS_FILES) -o server
		@echo $(FONT_COLOR_GREEN)[server executable create]$(FONT_COLOR_WHITE)
		@$(CC) $(FONT_COLOR_CFLAGS) $(OBJS_CLIENT_FILES) $(OBJS_UTILS_FILES) -o client
		@echo $(FONT_COLOR_GREEN)[client executable create]$(FONT_COLOR_WHITE)

$(OBJS):	$(SRCS_PATH)
			@$(CC) $(CFLAGS) $(SRCS_PATH) -c
			@echo $(FONT_COLOR_GREEN)[objects file compile]$(FONT_COLOR_WHITE)

bonus:	all

clean:
		@rm -f $(OBJS)
		@echo $(FONT_COLOR_GREEN)[objects files delete]$(FONT_COLOR_WHITE)

fclean:	clean
		@rm -f server
		@rm -f client
		@echo $(FONT_COLOR_GREEN)[executable files delete]$(FONT_COLOR_WHITE)

re:		fclean all

.PHONY:	clean fclean re all