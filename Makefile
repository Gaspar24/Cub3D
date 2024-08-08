
NAME = cub3d.exe

FLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux

LDFLAGS = -L$(MLX_DIR) -L/usr/lib/x86_64-linux-gnu/ -lX11 -lXext -lm -lbsd -lmlx

MLX = minilibx-linux/libmlx.a

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):  $(MLX) $(OBJ)
		cc $(FLAGS) $(OBJ) $(MLX) $(LDFLAGS) -o $(NAME)
		rm -rf $(OBJ)

$(MLX):
		make -C $(MLX_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


