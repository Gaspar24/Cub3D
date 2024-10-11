/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:53:27 by pfalli            #+#    #+#             */
/*   Updated: 2024/09/19 10:53:49 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/cub3d.h"


int	close_window(t_data *data, t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->mlx_p, mlx->window);
	if (mlx->mlx_p)
	{
		mlx_destroy_display(mlx->mlx_p);
		free(mlx->mlx_p);
	}
	printf("GAME OVER!\n");
	free_map(data);
	free_data(data);
	exit(EXIT_SUCCESS);
    return(0);
}

void	exit_error(t_data *data,char *str)
{
	printf("%s/n", str);
	free_map(data);
	free_data(data);
	exit(EXIT_FAILURE);
}

void free_map(t_data *data)
{
    int i = 0;
    while (data->map_two_d[i])
    {
        free(data->map_two_d[i]);
        i++;
    }
    free(data->map_two_d);
}


void free_data(t_data *data)
{
    if (data == NULL)
        return;
    if (data->no_path != NULL)
    {
        //printf("Freeing no_path\n");
        free(data->no_path);
    }
    if (data->so_path != NULL)
    {
        //printf("Freeing so_path\n");
        free(data->so_path);
    }
    if (data->we_path != NULL)
    {
        //printf("Freeing we_path\n");
        free(data->we_path);
    }
    if (data->ea_path != NULL)
    {
        //printf("Freeing ea_path\n");
        free(data->ea_path);
    }
    if (data->map_path != NULL)
    {
        //printf("Freeing map_path\n");
        free(data->map_path);
    }
    //printf("END freeing data\n");
}