CC = gcc
CFLAGS    := -Wall -Werror -Wextra
# ASAN_FLAGS = -fsanitize=address

SRCS_DIR = mandatory
SRCS_DIR_BONUS = bonus
OBJS_DIR = .
UTILS_DIR = utils/srcs

FONT_COLOR_GREEN = '\033[0;32m'
FONT_COLOR_DEFAULT = '\033[0m'

SERVER_SRCS_FILES = server.c
CLIENT_SRCS_FILES = client.c
SERVER_SRCS_FILES_BONUS = server_bonus.c
CLIENT_SRCS_FILES_BONUS = client_bonus.c
UTILS_FILES = utils1.c utils2.c utils3.c

OBJS_SERVER = $(SERVER_SRCS_FILES:%.c=%.o)
OBJS_CLIENT = $(CLIENT_SRCS_FILES:%.c=%.o)
OBJS_UTILS = $(UTILS_FILES:%.c=%.o)

SERVER_SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(SERVER_SRCS_FILES))
CLIENT_SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(CLIENT_SRCS_FILES))
UTILS_PATH = $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))
SRCS_PATH = $(SERVER_SRCS_PATH) $(CLIENT_SRCS_PATH)

OBJS_SERVER_FILES = $(addprefix $(OBJS_DIR)/, $(OBJS_SERVER))
OBJS_CLIENT_FILES = $(addprefix $(OBJS_DIR)/, $(OBJS_CLIENT))
OBJS_UTILS_FILES = $(addprefix $(OBJS_DIR)/, $(OBJS_UTILS))
OBJS = $(OBJS_SERVER_FILES) $(OBJS_CLIENT_FILES) 

# BONUS RULES
OBJS_SERVER_BONUS = $(SERVER_SRCS_FILES_BONUS:%.c=%.o)
OBJS_CLIENT_BONUS = $(CLIENT_SRCS_FILES_BONUS:%.c=%.o)

SERVER_SRCS_PATH_BONUS = $(addprefix $(SRCS_DIR_BONUS)/, $(SERVER_SRCS_FILES_BONUS))
CLIENT_SRCS_PATH_BONUS = $(addprefix $(SRCS_DIR_BONUS)/, $(CLIENT_SRCS_FILES_BONUS))
SRCS_PATH_BONUS = $(SERVER_SRCS_PATH_BONUS) $(CLIENT_SRCS_PATH_BONUS)

OBJS_SERVER_FILES_BONUS = $(addprefix $(OBJS_DIR)/, $(OBJS_SERVER_BONUS))
OBJS_CLIENT_FILES_BONUS = $(addprefix $(OBJS_DIR)/, $(OBJS_CLIENT_BONUS))
OBJS_BONUS = $(OBJS_SERVER_FILES_BONUS) $(OBJS_CLIENT_FILES_BONUS)

all:	$(OBJS) $(OBJS_UTILS_FILES)
		@$(CC) $(CFLAGS) $(ASAN_FLAGS) $(OBJS_SERVER_FILES) $(OBJS_UTILS_FILES) -o server
		@echo $(FONT_COLOR_GREEN)[server executable create]$(FONT_COLOR_DEFAULT)
		@$(CC) $(CFLAGS) $(ASAN_FLAGS) $(OBJS_CLIENT_FILES) $(OBJS_UTILS_FILES) -o client
		@echo $(FONT_COLOR_GREEN)[client executable create]$(FONT_COLOR_DEFAULT)

$(OBJS):	$(SRCS_PATH) $(UTILS_PATH)
			@$(CC) $(CFLAGS) $(ASAN_FLAGS) $(SRCS_PATH) $(UTILS_PATH) -c
			@echo $(FONT_COLOR_GREEN)[objects file compile]$(FONT_COLOR_DEFAULT)

bonus:	$(OBJS_BONUS) $(OBJS_UTILS_FILES)
		@$(CC) $(CFLAGS) $(OBJS_SERVER_FILES_BONUS) $(OBJS_UTILS_FILES) -o server_bonus
		@echo $(FONT_COLOR_GREEN)[server executable create]$(FONT_COLOR_DEFAULT)
		@$(CC) $(CFLAGS) $(OBJS_CLIENT_FILES_BONUS) $(OBJS_UTILS_FILES) -o client_bonus
		@echo $(FONT_COLOR_GREEN)[client executable create]$(FONT_COLOR_DEFAULT)

$(OBJS_BONUS):	$(SRCS_PATH_BONUS) $(UTILS_PATH)
				@$(CC) $(CFLAGS) $(SRCS_PATH_BONUS) $(UTILS_PATH) -c
				@echo $(FONT_COLOR_GREEN)[bonus objects file compile]$(FONT_COLOR_DEFAULT)

clean:
		@rm -f $(OBJS) $(OBJS_UTILS_FILES)
		@rm -f $(OBJS_BONUS)
		@echo $(FONT_COLOR_GREEN)[objects files delete]$(FONT_COLOR_DEFAULT)

fclean:	clean
		@rm -f server server_bonus
		@rm -f client client_bonus
		@echo $(FONT_COLOR_GREEN)[executable files delete]$(FONT_COLOR_DEFAULT)

re:		fclean all

.PHONY:	clean fclean re all