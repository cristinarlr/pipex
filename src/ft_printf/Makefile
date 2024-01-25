# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 14:26:02 by crramire          #+#    #+#              #
#    Updated: 2024/01/12 11:02:29 by Cristina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors ----------------------------------------------------- #
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
MAGENTA = \033[0;35m
BLUE = \033[0;34m
CIAN = \033[0;36m
WHITE = \033[0;37m
END = \033[0m
# ------------------------------------------------------------ #

LIB = ar rc
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = 	ft_printf.c \
		ft_printf_ut_strchr.c \
		ft_printf_ut_num.c \
		ft_printf_ut_ptr.c \

OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)
	@echo "$(GREEN)[+] $(BLUE)  $(NAME) compilada! $(END)"
	
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $(<) -o $(@)

clean:
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "$(MAGENTA)[+] $(BLUE)  Archivos objeto .o $(NAME) borrados $(END)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(MAGENTA)[+] $(BLUE) $(NAME) borrado $(END)"

re: fclean all

.PHONY: all clean fclean re
