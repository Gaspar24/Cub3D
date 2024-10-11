/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:09:23 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/07 13:09:23 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// int	close_window(t_data *data, t_mlx *mlx)
// {
// 	if (mlx->window)
// 		mlx_destroy_window(mlx->mlx_p, mlx->window);
// 	if (mlx->mlx_p)
// 	{
// 		mlx_destroy_display(mlx->mlx_p);
// 		free(mlx->mlx_p);
// 	}
// 	printf("GAME OVER!\n");
// 	free_map(data);
// 	free_data(data);
// 	exit(EXIT_SUCCESS);
// 	return (0);
// }

#include "mlx.h" // Ensure you include the necessary header for mlx functions

void free_textures1(t_data *data, t_mlx *mlx)
{
	if (data->textures.no)
	{
		mlx_destroy_image(mlx->mlx_p, data->textures.no);
		data->textures.no = NULL;
	}
	if (data->textures.so)
	{
		mlx_destroy_image(mlx->mlx_p, data->textures.so);
		data->textures.so = NULL;
	}
	if (data->textures.we)
	{
		mlx_destroy_image(mlx->mlx_p, data->textures.we);
		data->textures.we = NULL;
	}
	if (data->textures.ea)
	{
		mlx_destroy_image(mlx->mlx_p, data->textures.ea);
		data->textures.ea = NULL;
	}
}

int close_window(t_game *game)
{
	free_textures1(game->data, game->mlx); // Free textures first

	if (game->mlx->window)
		mlx_destroy_window(game->mlx->mlx_p, game->mlx->window);
	if (game->mlx->mlx_p)
	{
		mlx_destroy_display(game->mlx->mlx_p);
		free(game->mlx->mlx_p);
	}
	printf("GAME OVER!\n");
	free_map(game->data);
	free_data(game->data);
	// free(game->player);
	exit(EXIT_SUCCESS);
	return (0);
}

void	exit_error(t_data *data, char *str)
{
	printf("%s/n", str);
	// printf("here: exit_error\n");
	free_map(data);
	free_data(data);
    mlx_destroy_display(data->mlx->mlx_p);
	free(data->mlx->mlx_p);
	exit(EXIT_FAILURE);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map_two_d)
	{
		while (data->map_two_d[i])
		{
			free(data->map_two_d[i]);
			i++;
		}
		free(data->map_two_d);
		data->map_two_d = NULL;
	}
}

void	free_data(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->no_path != NULL)
		free(data->no_path);
	if (data->so_path != NULL)
		free(data->so_path);
	if (data->we_path != NULL)
		free(data->we_path);
	if (data->ea_path != NULL)
		free(data->ea_path);
	if (data->map_path != NULL)
		free(data->map_path);
	if(data->player != NULL)
		free(data->player);
}
