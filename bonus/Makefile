RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

NAME = cub3d

SRC = src/mini_map.c src/map.c src/utils.c src/errors.c src/debug.c src/free.c \
		 src/main.c src/raycasting.c src/actions.c src/data_init.c src/movement.c

CC = gcc
CCFLAGS = -Wall -Werror -Wextra -g
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# -L/usr/X11/lib -lX11 -lXext -lm "ON MAC"...... and also without $(X11_LIBS) in line 31
# gcc -Wall -Wextra -Werror -g so_long.c -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11  "ON MY LAPTOP"

LIBFT = ./libft_full/libft.a
LIBFT_PATH = ./libft_full
MLX_DIR = ./minilibx-linux
MLX = ./minilibx-linux/libmlx.a

X11_LIBS = -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

$(NAME):
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_PATH)
	@echo "$(YELLOW)Libft Compiled$(RESET)"
	@$(CC) $(CCFLAGS) $(MLX_FLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MLX) $(X11_LIBS) -lm
	@echo "$(YELLOW)Cub3d Compiled$(RESET)"
	@echo "$(GREEN)Ready!$(RESET)"

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@echo "$(RED)Cub3d Cleaned$(RESET)"

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) map/valid
#	valgrind --leak-check=full --show-leak-kinds=all --suppressions=valgrind.supp ./cub3d map/valid.ber

re : fclean all

# gcc so_long.c -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
# valgrind --leak-check=full --show-leak-kinds=all

