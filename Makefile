########################### VARIABLES ###########################

# Colors ----------------------------------------------------- #
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
MAGENTA = \033[0;35m
BLUE = \033[0;34m
CIAN = \033[0;36m
WHITE = \033[0;37m
END = \033[0m

# Final program ---------------------------------------------- #
NAME = pipex
NAME_B = pipex_bonus

# Source files ----------------------------------------------- #
SRCS = $(SRC_FILES)

SRC_DIR = src
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC_CFILES))
SRC_CFILES =	main.c \
				path.c \
				execute.c \
				error_manage.c \
				pipex.c \
				utils.c \


# Source/linker files ---------------------------------------- #
LIBFT_DIR =$(SRC_DIR)/libft
PRINTF_DIR =$(SRC_DIR)/ft_printf

# Object files ----------------------------------------------- #
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJ_DIR = obj

# Include files (header) ------------------------------------- #
INCL_DIR = includes

# Compiler options ------------------------------------------- #
CC = gcc
CFLAGS = -Wall -Wextra -Werror  $(SANITIZE)
LINKFLAGS = -L./$(LIBFT_DIR) -lft -L./$(PRINTF_DIR) -lftprintf

#SANITIZE=
SANITIZE=-g -fsanitize=address


########################## BONUS ###############################

# Bonus Source files ----------------------------------------------- #
SRCS_B = $(SRC_FILES_B)

SRC_DIR_B = src_bonus
SRC_FILES_B = $(addprefix $(SRC_DIR_B)/, $(SRC_CFILES_B))
SRC_CFILES_B =	main_bonus.c \
				path_bonus.c \
				execute_bonus.c \
				error_manage_bonus.c \
				pipex_bonus.c \
				utils_bonus.c \

# Bonus Object files ----------------------------------------------- #
OBJS_B = $(patsubst $(SRC_DIR_B)/%.c,$(OBJ_DIR_B)/%.o,$(SRCS_B))
OBJ_DIR_B = obj_bonus

# Include files (header) ------------------------------------- #
#Hace falta?
INCL_DIR = includes

########################## RULES ###############################

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $(LINKFLAGS) $(FRAMEWORKS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)[+] $(NAME) COMPILED $(END)"
	@echo "\n"
	@echo "$(YELLOW) ██████╗ ██╗██████╗ ███████╗██╗  ██╗     ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗██╗     ███████╗██████  $(END)"
	@echo "$(YELLOW) ██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝    ██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║██║     ██╔════╝██╔══██╗$(END)"
	@echo "$(YELLOW) ██████╔╝██║██████╔╝█████╗   ╚███╔╝     ██║     ██║   ██║██╔████╔██║██████╔╝██║██║     █████╗  ██║  ██║$(END)"
	@echo "$(YELLOW) ██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗     ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║██║     ██╔══╝  ██║  ██║$(END)"
	@echo "$(YELLOW) ██║     ██║██║     ███████╗██╔╝ ██╗    ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ██║███████╗███████╗██████╔╝$(END)"
	@echo "$(YELLOW) ╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝     ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═════╝ $(END)"
	@echo "\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I./$(INCL_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

bonus: $(NAME_B)

$(NAME_B): $(OBJS_B)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $(LINKFLAGS) $(FRAMEWORKS) -o $(NAME_B) $(OBJS_B)
	@echo "$(GREEN)[+] $(NAME_B) COMPILED $(END)"
	@echo "\n"
	@echo "$(YELLOW) ██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗ $(END)"
	@echo "$(YELLOW) ██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝ $(END)"
	@echo "$(YELLOW) ██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗ $(END)"
	@echo "$(YELLOW) ██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║ $(END)"
	@echo "$(YELLOW) ██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║ $(END)"
	@echo "$(YELLOW) ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝ $(END)"
	@echo "\n"

$(OBJ_DIR_B)/%.o: $(SRC_DIR_B)/%.c | $(OBJ_DIR_B)
	@$(CC) $(CFLAGS) -I./$(INCL_DIR_B) -c $< -o $@

$(OBJ_DIR_B):
	@mkdir -p $(OBJ_DIR_B)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(MAGENTA)[+] Object .o files ERASED $(END)"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@rm -f $(NAME)
	@echo "$(MAGENTA)[+] $(NAME) ERASED $(END)"

re: fclean all

.PHONY: all clean fclean re
