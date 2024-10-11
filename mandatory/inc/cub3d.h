#ifndef CUB3D_H
# define CUB3D_H


# include "../libft_full/inc/ft_printf.h"
# include "../libft_full/inc/libft.h"
# include "../libft_full/inc/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>



#define MAP_WIDTH 16
#define MAP_HEIGHT 24
#define S_W 1600    // Define screen width
#define S_H 900  // Define screen height
#define FOV_ANGLE (M_PI / 3) // 60 degrees field of view

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
#define KEY_LEFT 65361
#define KEY_RIGHT 65363

# define KEY_ESC 65307
# define TS 40

# define SIZE 40
# define WIDTH 1600
# define HEIGHT 900

//***colors */
#define ORANGE "\033[38;5;214m"
#define RESET "\033[0m"


#define CHECK_NULL_AND_RETURN(ptr) if ((ptr) == NULL) return -1


// extern char map2d[MAP_HEIGHT][MAP_WIDTH + 1];

typedef struct s_game t_game;
typedef struct s_mlx t_mlx;

typedef struct s_point
{
    int x;
    int y;
} t_point;

typedef struct s_rgb
{
    int r;
    int g;
    int b;
} t_rgb;

typedef struct s_player
{

    float playerX;
    float playerY;
    float playerA;
    float FOV;  // Field of View (60 degrees)
    float depth;  // Maximum depth of the map (distance of ray)
    float move_speed;
    float turn_speed;
    int testX; // the coordinates in the map that the ray is curently checking;
    int testY;

}				t_player;


typedef struct s_rays
{
	int 	stepX;
	int 	stepY;
	float	side_distX;
	float	side_distY;
	float	delta_distX;
	float	delta_distY;
	float 	ray_dirX;
	float 	ray_dirY;
	int 	mapX;
	int 	mapY;
	float	*wall_x;
	int		hit_side;

}	t_rays;

typedef struct s_keys
{
    int move_forward;
    int move_backward;
    int move_left;
    int move_right;
    int turn_left;
    int turn_right;
} t_keys;

typedef struct s_map
{
	int			width;
	int			height;
	int			point_x;
	int			point_y;
	int			lines;
}				t_map;

typedef struct s_textures
{
    void    *no;
    void    *we;
    void    *ea;
    void    *so;
    char    *no_data;
    char    *we_data;
    char    *ea_data;
    char    *so_data;
}				t_textures;

typedef struct s_data
{
	t_textures textures;
	int			width;
	int			height;
	char		*map_path;
	char		**map_two_d;
	t_map		*map;
	t_player	*player;
	int			floor_color;
    int			ceiling_color;
	char        *no_path;
    char        *so_path;
    char        *we_path;
    char        *ea_path;
	//--test--
	int img_width;
	int img_height;
	int bits_per_pixel, size_line, endian;
	char *wall_data;
	void	*img;
	char	*img_data;
	void	*wall_img;
	int			wall_color;
	int		wall_type;
	float		wall_x;
	t_keys keys;
	t_rgb *rgb;
	int		flood_x;
	int		flood_y;
	int player_x;
	int player_y;

	t_game *game;
	t_mlx	*mlx;
}               t_data;


typedef struct s_mlx	
{
	void			*img;	// the image
	void			*window; // mlx window
	void			*mlx_p;	// the mlx pointer
	t_player		*player; // pointer to player struct
    t_data			*data;   // pointer to data struct

}	t_mlx;

typedef struct s_game
{
    t_mlx *mlx;
    t_player *player;
    t_data *data;
	// t_keys *keys;
} t_game;



// *** map.c***
int	map_two_d(t_data *data, int skip_lines);
void parsing_map(t_data *data);
int parse_color(char *color_str);
void store_paths(t_data *data);

// *** utils.c **
int ft_strspn(const char *str, const char *accept);
char *ft_strtok(char *str, const char *delim) ;
int ft_sscanf(const char *str, const char *format, t_rgb *color);
int is_map_line(const char *line);
bool is_map_closed(char **map, t_data *data);
void flood_fill(char **map_copy, int y, int x, t_data *data);
char **copy_map(char **map, int height);
size_t ft_strcspn(const char *s, const char *reject);
int new_strncmp(const char *s1, const char *s2, int n);
int check_null_and_return(void *ptr);
void	check_first_line(t_data *data);


// ***flood.map.c***
void replace_hiddenchars_with_spaces(char **map, int height);

// *** errors.c***
bool	exist_player(char c);

void invalid_char(t_data *data);
void check_errors(t_data *data);
void check_colours(t_data *data);
bool	exist_player(char c);
void check_all_paths(t_data *data);

// *** free.c ***
void free_map(t_data *data);
void free_mlx(t_data *data);
// int	close_window(t_data *data, t_mlx *mlx);
void	exit_error(t_data *data,char *str);
// void	free_map_copy(char **map_copy, int height);
void	free_textures(t_data *data);

// *** debug.c ***
void debug_print_wall_path(t_data *data);
void	debug_print_map(char **map);
void free_data(t_data *data);
void debug_print_asci_string(char *str);


//***map2.cub** */
char *trim_line(char *line);
void calculate_map_dimensions(t_data *data);
int	map_is_last(t_data *data);


void  no_player(t_data *data);

int mouse_move(int x, int y, t_game *game);

int update_player(t_game *game);

void	error( t_data *data,char *str);
void replace_spaces_with_zeros(char **map, int height);

void	trim_paths(t_data *data);
int check_path(char *str);
int	is_empty_or_whitespace_line(const char *line);

//***norminette ***
int	open_map_file(t_data *data);
void	allocate_map_memory(t_data *data);
void	skip_lines_in_file(int fd, int skip_lines);

// ***helper_functions.c***
void count_commas(char *str);
void check_color_string(char *string);
void print_error(char *str);
char *trim_char(char *str, char ch);
int	ft_isspace(char c);
void	replace(char **map, int height);



///----------------- data_init----------------
t_player *init_player(t_data *data);
void init_keys(t_keys *keys);
void	init_paths(t_data *data);



// ---------------raycsting----------------
int redraw_image(t_game *game_loop);
void	load_textures(t_data *data, t_mlx *mlx);
//----------------actionns---------------------
// int key_press(int keysym, t_mlx *mlx, t_data *data);
// int key_release(int keysym, t_mlx *mlx, t_data *data);
void	update_player_position(t_player *player, t_keys *keys, t_data *data);
int 	key_release(int keycode, t_game *game);
int 	key_press(int keycode, t_game *game);
float	cast_rays(int x, t_player *player, t_data *data, float *wall_x);
// ----------------load_textures---------------
void	load_textures(t_data *data, t_mlx *mlx);

// --------------red cross hook----------------
int	close_window(t_game *game);

// --------------helper_functions--------------
bool	check_map_format(char *str);

// ------neeed new_file-------
void	exit_before_window_open(t_data *data, char *str);



#endif