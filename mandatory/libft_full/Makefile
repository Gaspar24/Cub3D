NAME = libft.a

# Directories
INC = inc/
SRC_DIR = src/
OBJ_DIR = obj/

# compilers and flags
CC = gcc
FLAGS = -Wall -Werror -Wextra -I

# source files
LIBFT_FILES = $(addprefix $(SRC_DIR)libft/, ft_isalpha.c \
												ft_memmove.c \
												ft_strjoin.c \
												ft_isdigit.c \
												ft_memchr.c\
												ft_strtrim.c \
												ft_isalnum.c \
												ft_strnstr.c \
												ft_itoa.c \
												ft_isascii.c \
												ft_strrchr.c \
												ft_strmapi.c \
												ft_isprint.c\
												ft_strchr.c \
												ft_striteri.c \
												ft_strlen.c \
												ft_strncmp.c \
												ft_striteri.c \
												ft_memset.c \
												ft_memcmp.c \
												ft_putchar_fd.c \
												ft_bzero.c \
												ft_tolower.c \
												ft_putstr_fd.c \
												ft_memcpy.c \
												ft_toupper.c \
												ft_putendl_fd.c \
												ft_strlen.c \
												ft_atoi.c \
												ft_split.c \
												ft_strlcpy.c \
												ft_calloc.c \
												ft_substr.c \
												ft_strlcat.c \
												ft_strdup.c)

PRINTF_FILES = $(addprefix $(SRC_DIR)printf/, ft_printf.c \
												ft_print_char.c \
												ft_print_hexa.c \
												ft_print_nbr.c \
												ft_print_percentage.c \
												ft_print_ptr.c \
												ft_print_string.c \
												ft_print_u.c \
												ft_print_uphexa.c)

GNL_FILES = $(SRC_DIR)getnextline/get_next_line.c \
					$(SRC_DIR)getnextline/get_next_line_utils.c\

SRC =$(LIBFT_FILES) $(PRINTF_FILES) $(GNL_FILES)

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

# build rules
all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re