/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:10:03 by pfalli            #+#    #+#             */
/*   Updated: 2024/09/13 13:10:03 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


void draw_visual_cone(t_mlx *mlx, t_player *player, int cell_size)
{
    int player_x = (int)(player->playerX * (cell_size));
    int player_y = (int)(player->playerY * (cell_size));
    float angle_start = player->playerA - (player->FOV / 4); // change the cone size
    float angle_end = player->playerA + (player->FOV / 4);  
    float angle_step = player->FOV / 400; // change cone size

    for (float angle = angle_start; angle <= angle_end; angle += angle_step)
    {
        for (int dist = 0; dist < (player->depth * cell_size) / 4; dist++) // change cone size
        {
            int x = player_x + cos(angle) * dist;
            int y = player_y + sin(angle) * dist;
            mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, 0x00FF00); // Green for the cone
        }
    }
}

void draw_player(t_mlx *mlx, t_player *player, int cell_size)
{
	int player_size = cell_size / 1.5;
    int player_x = (int)(player->playerX * (cell_size));
    int player_y = (int)(player->playerY * (cell_size));
    int i = 0;
    while (i < player_size)
    {
        int j = 0;
        while (j < player_size)
        {
            mlx_pixel_put(mlx->mlx_p, mlx->window, player_x + i, player_y + j, 0x000000); // Red for player
            j++;
        }
        i++;
    }
	draw_visual_cone(mlx, player, cell_size);
}

void mini_map(t_data *data, t_mlx *mlx, t_player *player)
{
    int cell_size = 10;
    int x = 0, y = 0;

    while (data->map_two_d[y] != NULL)
    {
        x = 0;
        while (data->map_two_d[y][x] != '\0')
        {
            int color;
            if (data->map_two_d[y][x] == '1')
                color = 0x808080;
            else if (data->map_two_d[y][x] == '0')
                color = 0x8B4513;
            else if (data->map_two_d[y][x] == ' ')
                color = 0x808080;
            //  else
            //  {
            //      printf("Skipping invalid character '%c' at (%d, %d)\n", data->map_two_d[y][x], x, y);
            //      x++;
            //      continue;
            //  }
            //printf("Debug mini_map: cell (%d, %d) with value '%c' and color 0x%X\n", x, y, data->map_two_d[y][x], color);
            int i = 0;
            while (i < cell_size)
            {
                int j = 0;
                while (j < cell_size)
                {
                    mlx_pixel_put(mlx->mlx_p, mlx->window, x * cell_size + i, y * cell_size + j, color);
					// put_pixel_to_image(data, x * cell_size + i, y * cell_size + j, color);
                    j++;
                }
                i++;
            }
            x++;
        }
        y++;
    }
	draw_player(mlx, player, cell_size);
}

void calculate_map_dimensions(t_data *data)
{
    int height = 0;
    int width = 0;
    int current_width;

    while (data->map_two_d[height] != NULL)
    {
        current_width = ft_strlen(data->map_two_d[height]);
        if (current_width > width)
        {
            width = current_width;
        }
        height++;
    }
    data->height = height;
    data->width = width;
}
