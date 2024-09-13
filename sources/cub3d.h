

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"




# define MAX_LINE_LENGTH 1000
# define MAX_LINES 1000
#define TILE_SIZE 5

// # define S_W 1920 // Define screen width
// # define S_H 1080 // Define screen height

#define FOV_ANGLE (M_PI / 3) // 60 degrees field of view
#define NUM_RAYS S_W // One ray per vertical pixel column
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4	// player speed

typedef struct s_player
{
    double player_x;  // Player's X position on the map
    double player_y;  // Player's Y position on the map
    double angle;     // Player's current facing direction (angle in radians)
    double move_speed;
    double turn_speed;
}   t_player;

typedef struct s_color {
    int r;
    int g;
    int b;
} t_color;

typedef struct s_data {
    char    **map2d; 
    char    *NO, *SO, *WE, *EA; // Texture paths (Already present)
    t_color floor_color;
    t_color ceiling_color;
    int     player_x, player_y;
    char    player_orientation;
	void	*wall;
	void	*floor;
	t_player player; // Add the player structure here

} t_data;

typedef struct s_mlx	//the mlx structure
{
	void			*img;	// the image
	void			*window; // mlx window
	void			*mlx_p;	// the mlx pointer

}	t_mlx;



//----------------read_map------------------
char	**read_map(const char *filename, t_data *data);


//-----------------utils---------------------
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);

//----------put_texture-------
// void	draw_wall(t_data *data, int img_width, int img_height, t_mlx *mlx);
// void	draw_floor(t_data *data, int img_width, int img_height, t_mlx *mlx);

//----------actions-------------
int		handle_input(int keysym, t_mlx *mlx);
void	close_window(t_mlx *mlx);


//--------------raycasting------------
// void cast_rays(t_data *data, t_mlx *mlx);



#endif