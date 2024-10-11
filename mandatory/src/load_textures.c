/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:47:49 by msacaliu          #+#    #+#             */
/*   Updated: 2024/10/07 14:03:49 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// void cleanup(t_data *data)
// {
//     if (data->textures.no)
//         mlx_destroy_image(data->mlx->mlx_p, data->textures.no);
//     if (data->textures.so)
//         mlx_destroy_image(data->mlx->mlx_p, data->textures.so);
//     if (data->textures.we)
//         mlx_destroy_image(data->mlx->mlx_p, data->textures.we);
//     if (data->textures.ea)
//         mlx_destroy_image(data->mlx->mlx_p, data->textures.ea);
//     if (data->mlx->mlx_p)
//     {
//         mlx_destroy_display(data->mlx->mlx_p);
//         free(data->mlx->mlx_p);
//     }
// }

void	error( t_data *data,char *str) /// should destroy the image and check if data.texture is null
{
	printf("❌ERROR %s\n",str);
	mlx_destroy_display(data->mlx->mlx_p); // this should be after distroy image
	free(data->mlx->mlx_p); // this after destroy image.
	if(data->map_path != NULL)
		free(data->map_path);
	if (data->no_path != NULL)
		free(data->no_path);
	if (data->so_path != NULL)
		free(data->so_path);
	if (data->we_path != NULL)
		free(data->we_path);
	if (data->ea_path != NULL)
		free(data->ea_path);
	if(data->player != NULL)
		free(data->player);
	free_map(data);
	exit(1);
}

void	load_no_and_so(t_data *data, t_mlx *mlx)
{
	data->textures.no = mlx_xpm_file_to_image(mlx->mlx_p, data->no_path,
			&data->img_width, &data->img_height);
	if (!data->textures.no)
		error(data,"Error loading NO texture");

	data->textures.no_data = mlx_get_data_addr(data->textures.no,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.no_data)
		error(data,"Error getting data address for NO texture");
	data->textures.so = mlx_xpm_file_to_image(mlx->mlx_p, data->so_path,
			&data->img_width, &data->img_height);
	if (!data->textures.so)
		error(data,"Error loading SO texture");
	data->textures.so_data = mlx_get_data_addr(data->textures.so,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.so_data)
		error(data,"Error getting data address for SO texture");
}

void	load_we_and_ea(t_data *data, t_mlx *mlx)
{
	data->textures.we = mlx_xpm_file_to_image(mlx->mlx_p, data->we_path,
			&data->img_width, &data->img_height);
	if (!data->textures.we)
		error(data,"Error loading WE texture");
	data->textures.we_data = mlx_get_data_addr(data->textures.we,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.we_data)
		error(data,"Error getting data address for WE texture");
	data->textures.ea = mlx_xpm_file_to_image(mlx->mlx_p, data->ea_path,
			&data->img_width, &data->img_height);
	if (!data->textures.ea)
		error(data,"Error loading EA texture");
	data->textures.ea_data = mlx_get_data_addr(data->textures.ea,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.ea_data)
		error(data,"Error getting data address for EA texture");
}

void	load_textures(t_data *data, t_mlx *mlx)
{
	load_no_and_so(data, mlx);
	load_we_and_ea(data, mlx);
}
