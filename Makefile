

NAME = cub3d.exe

FLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux

MLX_FLAGS = -L$(MLX_DIR) -L/usr/lib/x86_64-linux-gnu -lm -lbsd

MLX_LIBS = -lmlx -lX11 -lXext

MLX = minilibx-linux/libmlx.a

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
		cc $(OBJ) $(MLX) $(MLX_FLAGS) $(MLX_LIBS) $(FLAGS) -o $(NAME)
		rm -rf $(OBJ)

$(MLX):
		make -C $(MLX_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
