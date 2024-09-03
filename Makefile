NAME = cub3d.exe

FLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux

LDFLAGS = -L$(MLX_DIR) -L/usr/lib/x86_64-linux-gnu/ -lX11 -lXext -lm -lbsd -lmlx

MLX = minilibx-linux/libmlx.a

SRC = sources/main.c sources/read_map.c sources/utils.c

OBJ = $(SRC:.c=.o)
# GET_NEXT_LINE = lib/get_next_line/a.out

all: $(NAME) 


$(NAME): $(MLX) $(OBJ)
		cc $(FLAGS) $(OBJ) $(MLX) $(LDFLAGS) -o $(NAME) 
		rm -f $(OBJ)
		rm -f $(NAME).0
		

$(MLX):
		make -C $(MLX_DIR)

# $(GET_NEXT_LINE):
# 		cc $(FLAGS) lib/get_next_line/get_next_line.c get_next_line.utils

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

# /////te4st

# NAME = cub3d.exe

# FLAGS = -Wall -Wextra -Werror

# MLX_DIR = minilibx-linux

# LDFLAGS = -L$(MLX_DIR) -L/usr/lib/x86_64-linux-gnu/ -lX11 -lXext -lm -lbsd -lmlx

# MLX = minilibx-linux/libmlx.a

# SRC = sources/main.c

# GNL_SRC = lib/get_next_line/get_next_line.c lib/get_next_line/get_next_line_utils.c

# OBJ = $(SRC:.c=.o) $(GNL_SRC:.c=.o)

# all: $(NAME)

# $(NAME): $(MLX) $(OBJ)
# 	cc $(FLAGS) $(OBJ) $(MLX) $(LDFLAGS) -o $(NAME)

# $(MLX):
# 	make -C $(MLX_DIR)

# %.o: %.c
# 	cc $(FLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all