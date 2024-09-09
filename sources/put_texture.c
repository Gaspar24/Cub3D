/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:19:43 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/09 14:20:10 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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