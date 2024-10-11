/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:36:59 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/23 13:27:44 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function calculates the direction of the ray from the player's
// position. It determines the step direction (stepX, stepY)
// and the initial distances to the next X and Y grid lines 
// (side_distX, side_distY).
void	initialize_ray(t_player *player, t_rays *rays)
{
	if (rays->ray_dirX < 0)
	{
		rays->stepX = -1;
		rays->side_distX = (player->playerX
				- (int)player->playerX) * rays->delta_distX;
	}
	else
	{
		rays->stepX = 1;
		rays->side_distX = ((int)player->playerX
				+ 1.0 - player->playerX) * rays->delta_distX;
	}
	if (rays->ray_dirY < 0)
	{
		rays->stepY = -1;
		rays->side_distY = (player->playerY
				- (int)player->playerY) * rays->delta_distY;
	}
	else
	{
		rays->stepY = 1;
		rays->side_distY = ((int)player->playerY
				+ 1.0 - player->playerY) * rays->delta_distY;
	}
}

// The DDA algorithm works by stepping through the grid, checking which cell
// the ray intersects.
// It moves from one grid line to the next until it hits a wall

void	perform_dda(t_rays *rays, t_data *data, bool *hit_wall)
{
	*hit_wall = false;
	while (!*hit_wall)
	{
		if (rays->side_distX < rays->side_distY)
		{
			rays->side_distX += rays->delta_distX;
			rays->mapX += rays->stepX;
			rays->hit_side = 0;
		}
		else
		{
			rays->side_distY += rays->delta_distY;
			rays->mapY += rays->stepY;
			rays->hit_side = 1;
		}
		if (data->map_two_d[rays->mapY][rays->mapX] == '1')
			*hit_wall = true;
	}
}

// After a wall is hit, this function calculates the perpendicular 
// distance to the wall, 
// which is needed to correctly scale the wall height on the screen.
//  also determines whether the wall is vertical or
//  horizontal (based on hit_side)
// Finally, it computes wall_x, the fractional 
// X-coordinate on the wall where the ray 
// hit, which is used for texture mapping.
float	calculate_perpendicular_distance(t_rays *rays, t_player *player,
	float *wall_x, int *wall_type)
{
	float	perp_wall_dist;

	if (rays->hit_side == 0)
	{
		perp_wall_dist = (rays->mapX - player->playerX
				+ (1 - rays->stepX) / 2) / rays->ray_dirX;
		*wall_x = player->playerY + perp_wall_dist * rays->ray_dirY;
		if (rays->ray_dirX > 0)
			*wall_type = 1;
		else
			*wall_type = 2;
	}
	else
	{
		perp_wall_dist = (rays->mapY - player->playerY
				+ (1 - rays->stepY) / 2) / rays->ray_dirY;
		*wall_x = player->playerX + perp_wall_dist * rays->ray_dirX;
		if (rays->ray_dirY > 0)
			*wall_type = 3;
		else
			*wall_type = 0;
	}
	*wall_x -= floor(*wall_x);
	return (perp_wall_dist);
}

float	cast_rays(int x, t_player *player, t_data *data, float *wall_x)
{
	t_rays	rays;
	float	perp_wall_dist;
	float	ray_angle;
	bool	hit_wall;

	hit_wall = false;
	rays.mapX = (int)player->playerX;
	rays.mapY = (int)player->playerY;
	ray_angle = (player->playerA - player->FOV / 2.0f)
		+ ((float)x / (float)S_W) * player->FOV;
	rays.ray_dirX = cosf(ray_angle);
	rays.ray_dirY = sinf(ray_angle);
	rays.delta_distX = fabsf(1 / rays.ray_dirX);
	rays.delta_distY = fabsf(1 / rays.ray_dirY);
	initialize_ray(player, &rays);
	perform_dda(&rays, data, &hit_wall);
	perp_wall_dist = calculate_perpendicular_distance(&rays,
			player, wall_x, &data->wall_type);
	return (perp_wall_dist * cosf(ray_angle - player->playerA));
}
