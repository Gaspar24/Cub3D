/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:10:46 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/06 12:46:54 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"


// void game_loop(void *ml) // game loop
// {
// 	t_mlx *mlx;

// 	mlx = ml; // cast to the mlx structure
// 	mlx_delete_image(mlx->mlx_p, mlx->img); // delete the image
// 	mlx->img = mlx_new_image(mlx->mlx_p, S_W, S_H); // create new image
// 	hook(mlx, 0, 0); // hook the player
// 	cast_rays(mlx); // cast the rays
// 	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0); // put the image to the window
// }

void    startup(t_data *data, char *filename)
{
    char *full_path = ft_strjoin("./sources/maps/", filename);
	full_path = ft_strjoin(full_path, ".cub");
    data->map2d = read_map(full_path, data);
    int i = 0;
    
}

void	draw_floor(t_data *data, int img_width, int img_height, t_mlx *mlx) //test
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	data->floor = mlx_xpm_file_to_image(mlx->mlx_p,
			"./sources/textures/floor.xpm", &img_width, &img_height);
	i = 0;
	while (data->map2d[i] != NULL)
	{
		j = 0;
		while (data->map2d[i][j] != '\0')
		{
			if (data->map2d[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx_p,
					mlx->window, data->floor, x, y);
			x += img_width;
			j++;
		}
		y += img_height;
		x = 0;
		i++;
	}
}

void	draw_wall(t_data *data, int img_width, int img_height, t_mlx *mlx) //test
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	data->wall = mlx_xpm_file_to_image(mlx->mlx_p,
			"./sources/textures/wall.xpm", &img_width, &img_height);
	i = 0;
	while (data->map2d[i] != NULL)
	{
		j = 0;
		while (data->map2d[i][j] != '\0')
		{
			if (data->map2d[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_p,
					mlx->window, data->wall, x, y);
			x += img_width;
			j++;
		}
		y += img_height;
		x = 0;
		i++;
	}
}

int main(int argc, char **argv)
{
    t_mlx    mlx;
    t_data data;
    
    if(argc != 2)
    {
        printf("Error\n");
        exit(1);
    }

    int		img_width = 550;
	int		img_height = 550;

    startup(&data, argv[1]);
    mlx.mlx_p = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx_p,1920,1080,"Maze Runner");
    // mlx.img = mlx_xpm_file_to_image(mlx.mlx_p,"./sources/textures/floor.xpm", &img_height, &img_height);
    // mlx_put_image_to_window(mlx.mlx_p,mlx.window, mlx.img, 150,150);
    draw_wall(&data, 50,50,&mlx);
    draw_floor(&data, 50,50,&mlx);

    // if(mlx.img==NULL)
    //     exit(1);
    mlx_loop(mlx.mlx_p);
    return(0);
}

