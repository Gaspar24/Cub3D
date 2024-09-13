NAME = cub3d.exe

FLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux

LDFLAGS = -L$(MLX_DIR) -L/usr/lib/x86_64-linux-gnu/ -lX11 -lXext -lm -lbsd -lmlx

MLX = minilibx-linux/libmlx.a

SRC = sources/main.c sources/read_map.c sources/utils.c sources/put_texture.c \
	sources/actions.c sources/raycasting.c

OBJ = $(SRC:.c=.o)
# GET_NEXT_LINE = lib/get_next_line/a.out

all: $(NAME) 

$(NAME): $(MLX) $(OBJ)
		cc	$(FLAGS) $(OBJ) $(MLX) $(LDFLAGS) -o $(NAME)
		rm -f $(OBJ)
	

$(MLX):
		make -C $(MLX_DIR)

# %.o:	%.c
# 		cc $(FLAGS) -c $< -o $@


clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all


