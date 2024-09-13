/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:07:03 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/13 13:54:30 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void render_wall_slice(int x, double distance, t_data *data, t_mlx *mlx, double ray_angle)
// {
//     int wall_height;
//     int draw_start;
//     int draw_end;

//     // Correct the fish-eye effect by adjusting the distance with the player's angle
//     distance = distance * cos(data->player.angle - ray_angle);

//     // Calculate wall height based on distance
//     wall_height = (TILE_SIZE / distance) * (S_W / 2);

//     draw_start = (S_H / 2) - (wall_height / 2);
//     draw_end = draw_start + wall_height;

//     // Draw the wall slice (just a simple rectangle for now)
//     for (int y = draw_start; y < draw_end; y++)
//     {
//         mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, 0xFFFFFF); // White walls for now
//     }
// }

// double cast_single_ray(double ray_angle, t_data *data)
// {
//     double x_step, y_step;
//     double ray_x, ray_y;
//     double distance_to_wall = 0;

//     // Normalize the angle between 0 and 2*PI
//     if (ray_angle < 0) ray_angle += 2 * M_PI;
//     if (ray_angle > 2 * M_PI) ray_angle -= 2 * M_PI;

//     // Calculate the direction in which the ray is going to step
//     // X and Y step are based on angle
//     x_step = cos(ray_angle);
//     y_step = sin(ray_angle);

//     ray_x = data->player.player_x;
//     ray_y = data->player.player_y;

//     while (1)
//     {
//         ray_x += x_step; // Move the ray forward in X direction
//         ray_y += y_step; // Move the ray forward in Y direction

//         // Check if the ray has hit a wall (1 in the map)
//         if (data->map2d[(int)ray_y / TILE_SIZE][(int)ray_x / TILE_SIZE] == '1')
//         {
//             // Calculate distance to the wall
//             distance_to_wall = sqrt(pow(ray_x - data->player.player_x, 2) + pow(ray_y - data->player.player_y, 2));
//             break;
//         }
//     }

//     return distance_to_wall;
// }


// void cast_rays(t_data *data, t_mlx *mlx)
// {
//     int x;
//     double ray_angle;
//     double ray_distance;a
//     ray_angle = data->player.angle - (FOV_ANGLE / 2); // Start from the leftmost angle of the FOV
//     for (x = 0; x < NUM_RAYS; x++) 
//     {
//         ray_distance = cast_single_ray(ray_angle, data); // Calculate distance for this ray
//         render_wall_slice(x, ray_distance, data, mlx, ray_angle); // Render the wall slice based on ray distance
//         ray_angle += FOV_ANGLE / NUM_RAYS; // Increment angle for the next ray
//     }
// }



