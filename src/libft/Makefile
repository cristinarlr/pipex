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

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS = 	ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_strlen.c		\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c 	\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_putstr_fd.c	\
		ft_putchar_fd.c	\
		ft_putendl_fd.c \
		ft_putnbr_fd.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\

BONUS_SOURCES = ft_lstnew_bonus.c 			\
				ft_lstadd_front_bonus.c 	\
				ft_lstsize_bonus.c 			\
				ft_lstlast_bonus.c			\
				ft_lstadd_back_bonus.c 		\
				ft_lstdelone_bonus.c		\
				ft_lstclear_bonus.c	 		\
				ft_lstiter_bonus.c 			\
				ft_lstmap_bonus.c			\

OBJ_DIR = obj

#con addprefix añadimos el path de la carpeta obj a los .o
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJECTS = $(addprefix $(OBJ_DIR)/, $(BONUS_SOURCES:.c=.o))

#OBJS = $(SRCS:%.c=%.o)
#BONUS_OBJECTS = $(BONUS_SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(BONUS_OBJECTS)
	@ar rc $(NAME) $(OBJS)
	@echo "$(GREEN)[+] $(BLUE) $(NAME) compilada! $(END)"
	@ar r $(NAME) $(BONUS_OBJECTS)
	@echo "$(GREEN)[+] $(BLUE) $(NAME) BONUS compilados!$(END)"

#bonus: $(BONUS_OBJECTS)
#	@ar r $(NAME) $(BONUS_OBJECTS)
#s	@echo "$(BLUE)[+] $(NAME) BONUS compilados!$(END)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $(<) -o $(@)

#%.o: %.c --->> esta es la versión en la que no metemos los .o en una carpeta
#	@$(CC) $(CFLAGS) -c $(<) -o $(@)

clean:
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJECTS)
	@rm -rf $(OBJ_DIR)
	@echo "$(MAGENTA)[+] $(BLUE)  Archivos objeto .o $(NAME) borrados $(END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(MAGENTA)[+] $(BLUE) $(NAME) borrado $(END)"

re: fclean all

.PHONY: all clean fclean re
