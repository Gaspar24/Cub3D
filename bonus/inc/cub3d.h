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
#define S_W 1920    // Define screen width
#define S_H 1080  // Define screen height
#define FOV_ANGLE (M_PI / 3) // 60 degrees field of view

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_E 101
# define KEY_Q 113

#define KEY_LEFT 65361
#define KEY_RIGHT 65363

#define KEY_F1 65470 // F1 key code
#define KEY_F2 65471 // F2 key code
#define KEY_F3 65472  // F3 key code
#define KEY_SPACE 32
#define KEY_ENTER 65293

# define KEY_ESC 65307
# define TS 40

# define SIZE 40
# define WIDTH 1600
# define HEIGHT 900

//***colors */
#define ORANGE "\033[38;5;214m"
#define RESET "\033[0m"


#define CHECK_NULL_AND_RETURN(ptr) if ((ptr) == NULL) return -1

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
	int lastX;


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
	// char	*gun_data; // the only weapon we render
    void    *no;
    void    *we;
    void    *ea;
    void    *so;
    char    *no_data;
    char    *we_data;
    char    *ea_data;
    char    *so_data;
	void	*weapon;
	char 	*weapon_data;
	void 	*axe;
	char 	*axe_data;
	// bool	is_axe;
	// bool	is_gun;
	void	*board;
	char 	*board_data;
	void	*menu;
	char 	*menu_data;
	void	*door;
	char 	*door_data;
	void	*open_door;
	char 	*open_door_data;


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
	bool	is_door;
	bool	is_open_door;
	bool	entered_trough_door;
	bool	is_fire;

	t_keys keys;
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
	t_textures textures;
	int menu;
	int start;
	// t_keys *keys;
} t_game;

typedef struct s_bonus
{
	t_mlx *mlx;
	t_player *player;
	t_data *data;
} 				t_bonus;



// *** map.c***
void	map_two_d(t_data *data, int skip_lines);
void parsing_map(t_data *data);
int parse_color(char *color_str);
void store_paths(t_data *data);

// *** utils.c **
int ft_strspn(const char *str, const char *accept);
char *ft_strtok(char *str, const char *delim) ;
int ft_sscanf(const char *str, const char *format, int *r, int *g, int *b);
int is_map_line(const char *line);
bool is_map_closed(char **map, t_data *data);
void flood_fill(char **map, int x, int y, t_data * data, bool *is_closed);
char **copy_map(char **map, int height);
size_t ft_strcspn(const char *s, const char *reject);

void mini_map(t_data *data, t_mlx *mlx, t_player *player);

// *** errors.c***
void invalid_char(t_data *data);
void check_errors(t_data *data);
void check_colours(t_data *data);

// *** free.c ***
void free_map(t_data *data);
void free_mlx(t_data *data);
int	close_window(t_data *data, t_mlx *mlx);
void	exit_error(t_data *data,char *str);

// *** debug.c ***
void debug_print_wall_path(t_data *data);
void debug_print_map(t_data *data);
void free_data(t_data *data);
void calculate_map_dimensions(t_data *data);

void  no_player(t_data *data);

int mouse_move(int x, int y, t_game *game);

int update_player(t_game *game);

void error(char *str);


///----------------- data_init----------------
t_player *init_player(t_data *data);
void init_keys(t_keys *keys);


// ---------------raycsting----------------
int redraw_image(t_game *game_loop);
void	load_textures(t_data *data, t_mlx *mlx);


//----------------actionns---------------------
// int key_press(int keysym, t_mlx *mlx, t_data *data);
// int key_release(int keysym, t_mlx *mlx, t_data *data);
void	update_player_position(t_player *player, t_keys *keys, t_data *data);
int 	key_release(int keycode, t_game *game);
int 	key_press(int keycode, t_game *game);


void render_menu(t_mlx *mlx);

// void move_character(t_player *player, t_data *data);
// void get_player_position(t_data *data, t_player *player);

#endif