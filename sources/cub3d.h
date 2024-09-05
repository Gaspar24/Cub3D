

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"


# define MAX_LINE_LENGTH 1000
# define MAX_LINES 1000
# define WIDTH 100
# define HEIGHT 100
# define X 0
# define Y 1
# define SIZE 50


// # define S_W 1900 // screen width
// # define S_H 1000 // screen height
// # define TILE_SIZE 30 // tile size
// # define FOV 60 // field of view
// # define ROTATION_SPEED 0.045 // rotation speed
// # define PLAYER_SPEED 4	// player speed

// typedef struct s_player //the player structure
// {
// 	int		plyr_x; // player x position in pixels
// 	int		plyr_y; // player y position in pixels
// 	double	angle;	// player angle
// 	float	fov_rd;	// field of view in radians
// 	int		rot;	// rotation flag
// 	int		l_r;	// left right flag
// 	int		u_d;	// up down flag
// }	t_player;

// typedef struct s_ray	//the ray structure
// {
// 	double	ray_ngl;	// ray angle
// 	double	distance;	// distance to the wall
// 	int		flag;		// flag for the wall
// }	t_ray;

typedef struct s_data	//the data structure
{
	char	**map2d;	// the map
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		p_x;		// player x position in the map
	int		p_y;		// player y position in the map
	int		w_map;		// map width
	int		h_map;	// map height
	/// c -color
	/// f -color

}	t_data;

typedef struct s_mlx	//the mlx structure
{
	void			*img;	// the image
	void			*window; // mlx window
	void			*mlx_p;	// the mlx pointer



	// t_ray			*ray;	// the ray structure
	// t_data			*dt;	// the data structure
	// t_player		*ply;	// the player structure
}	t_mlx;


//----------------read_map------------------
char	**read_map(const char *filename, t_data *data);

//-----------------utils---------------------
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);


#endif