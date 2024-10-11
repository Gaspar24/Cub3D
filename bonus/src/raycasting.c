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
// #include <float.h>

// # define IMG_SIZE = 50

void	render_door(t_data *data);

void	error(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}


void	load_textures(t_data *data, t_mlx *mlx)
{
	data->textures.no = mlx_xpm_file_to_image(mlx->mlx_p, data->no_path,
			&data->img_width, &data->img_height);
	if (!data->textures.no)
		error("Error loading NO texture");
	data->textures.no_data = mlx_get_data_addr(data->textures.no,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.no_data)
		error("Error getting data address for NO texture");
//---------------------------------------------------
	data->textures.so = mlx_xpm_file_to_image(mlx->mlx_p, data->so_path,
			&data->img_width, &data->img_height);
	if (!data->textures.so)
	{
		printf("%s\n", data->so_path);
		error("Error loading SO texture");
	}
	data->textures.so_data = mlx_get_data_addr(data->textures.so,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.so_data)
		error("Error getting data address for SO texture");
//--------------------------------------------------
	data->textures.we = mlx_xpm_file_to_image(mlx->mlx_p, data->we_path,
			&data->img_width, &data->img_height);
	if (!data->textures.we)
		error("Error loading WE texture");
	data->textures.we_data = mlx_get_data_addr(data->textures.we,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.we_data)
		error("Error getting data address for WE texture");
//---------------------------------------------------
	data->textures.ea = mlx_xpm_file_to_image(mlx->mlx_p, data->ea_path,
			&data->img_width, &data->img_height);
	if (!data->textures.ea)
		error("Error loading EA texture");
	data->textures.ea_data = mlx_get_data_addr(data->textures.ea,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.ea_data)
		error("Error getting data address for EA texture");
//---------------------------------------------------
	// Load weapon texture
    data->textures.weapon = mlx_xpm_file_to_image(mlx->mlx_p, "./textures/weapon/halo.xpm",
            &data->img_width, &data->img_height);
    if (!data->textures.weapon)
        error("Error loading weapon texture");
    data->textures.weapon_data = mlx_get_data_addr(data->textures.weapon,
            &data->bits_per_pixel, &data->size_line, &data->endian);
    if (!data->textures.weapon_data)
        error("Error getting data address for weapon texture");
// //---------------------------------------------------
	data->textures.board = mlx_xpm_file_to_image(mlx->mlx_p, "./textures/objects/board.xpm",
	            &data->img_width, &data->img_height);
	if (!data->textures.board)
	    error("Error loading weapon texture");
	data->textures.board_data = mlx_get_data_addr(data->textures.board,
	        &data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.board_data)
	    error("Error getting data address for weapon texture");
//---------------------------------------------------
	data->textures.axe = mlx_xpm_file_to_image(mlx->mlx_p, "./textures/weapon/axe.xpm",
	            &data->img_width, &data->img_height);
	if (!data->textures.axe)
	    error("Error loading axe texture");
	data->textures.axe_data = mlx_get_data_addr(data->textures.axe,
	        &data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.axe_data)
	    error("Error getting data address for axe texture");

//--------------------------DOOR----------------------
	data->textures.door = mlx_xpm_file_to_image(mlx->mlx_p, "./textures/objects/door_64.xpm",
	            &data->img_width, &data->img_height);
	if (!data->textures.door)
	    error("Error loading door texture");
	data->textures.door_data = mlx_get_data_addr(data->textures.door,
	        &data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.door_data)
	    error("Error getting data address for foor texture");
}


void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
    int	pixel_position;

    // Calculate the memory position of the pixel in the buffer
    pixel_position = (y * data->size_line) + (x * (data->bits_per_pixel / 8));

    // Check bounds to avoid writing outside the image data
    if (pixel_position < 0 || pixel_position >= data->size_line * S_H - (data->bits_per_pixel / 8))
    {
        return ;
    }
    // Update the pixel color in the image buffer (assuming 32 bits per pixel)
    data->img_data[pixel_position] = color & 0xFF;            // Blue
    data->img_data[pixel_position + 1] = (color >> 8) & 0xFF; // Green
    data->img_data[pixel_position + 2] = (color >> 16) & 0xFF; // Red
    if (data->bits_per_pixel == 32)
	{
        data->img_data[pixel_position + 3] = (color >> 24) & 0xFF; // Alpha channel (optional)
	}
}

void	render_column(int x, int ceiling, int floor, t_data *data)
{
	int		y;
	int		tex_x;
	int		tex_y;
	char	*pixel_addr;

	y = 0;
	while (y < S_H)
	{
		if (y < ceiling)
			put_pixel_to_image(data, x, y, data->ceiling_color);
		else if (y >= ceiling && y <= floor)
		{
			tex_x = (int)(data->wall_x * data->img_width);
			tex_y = (y - ceiling) * data->img_height / (floor - ceiling);
			pixel_addr = data->wall_data + (tex_y * data->img_width
				* (data->bits_per_pixel / 8)) + (tex_x * (data->bits_per_pixel / 8));
			data->wall_color = *(int *)pixel_addr;
			put_pixel_to_image(data, x, y, data->wall_color);
    	}
		else
			put_pixel_to_image(data, x, y,data->floor_color);
		y++;
	}
}

void render_weapon(t_data *data)
{
    int x, y;
    int tex_x, tex_y;
    char *pixel_addr;
    int scale_factor = 5; // Define the scaling factor to make it smaller
    int screen_x = (S_W - data->img_width * scale_factor) / 2 + 150; // move the pixels to right
    int screen_y = S_H - data->img_height * scale_factor; // Adjust for scaling

    y = 0;
    while (y < data->img_height * scale_factor)
    {
        x = 0;
        while (x < data->img_width * scale_factor)
        {
            tex_x = x / scale_factor;
            tex_y = y / scale_factor;
            pixel_addr = data->textures.weapon_data + (tex_y * data->img_width
                * (data->bits_per_pixel / 8)) + (tex_x * (data->bits_per_pixel / 8));
            data->wall_color = *(int *)pixel_addr;

            // don't print pixel transparent 0xFF0000
            if ((unsigned int)data->wall_color != 0xFF0000)
            {
                put_pixel_to_image(data, screen_x + x, screen_y + y, data->wall_color);
            }
            x++;
        }
        y++;
    }
}

void render_board(t_data *data)
{
    int		x, y;
    int		tex_x, tex_y;
    char	*pixel_addr;
    int		scale_factor = 2; // Define the scaling factor to make it smaller
    int		screen_x = 0; // move the pixels to right
    int		screen_y = S_H - data->img_height * scale_factor; // Adjust for scaling

    y = 0;
    while (y < data->img_height * scale_factor)
    {
        x = 0;
        while (x < data->img_width * scale_factor)
        {
            tex_x = x / scale_factor;
            tex_y = y / scale_factor;
            pixel_addr = data->textures.board_data + (tex_y * data->img_width
                * (data->bits_per_pixel / 8)) + (tex_x * (data->bits_per_pixel / 8));
            data->wall_color = *(int *)pixel_addr;
            put_pixel_to_image(data, screen_x + x, screen_y + y, data->wall_color);
            x++;
        }
        y++;
    }
}


//	void render_menu(t_mlx *mlx)
//	{
//	
//		int right = 600;
//		int down = 300;
//	    // Background color (set the window to black)
//	    mlx_clear_window(mlx->mlx_p, mlx->window);
//	
//	    // Title of the menu
//	    mlx_string_put(mlx->mlx_p, mlx->window, 150 + right, 50 + down, 0x00FF00, "WELCOME TO MAZE RUNNER");
//		
//	    // Menu options
//	    mlx_string_put(mlx->mlx_p, mlx->window, 100 + right, 150 + down, 0x00FF00, "1. Start Game");
//	    mlx_string_put(mlx->mlx_p, mlx->window, 100 + right, 200 + down, 0x00FF00, "2. Map selection");
//	    mlx_string_put(mlx->mlx_p, mlx->window, 100 + right, 250 + down, 0x00FF00, "3. Weapons selection");
//	    mlx_string_put(mlx->mlx_p, mlx->window, 100 + right, 300 + down, 0x00FF00, "4. Exit");
//	
//	    // Instructions to choose
//	    mlx_string_put(mlx->mlx_p, mlx->window, 100 + right, 350 + down, 0x00FF00, "Please press a key to select an option");
//	}

void render_object(int x, int ceiling, int floor, t_data *data)
{
	int		y;
	int		tex_x, tex_y;
	char	*pixel_addr;
	y = 0;
	while (y < S_H)
	{
        while (y > ceiling && y <= floor)
        {
            tex_x = (int)(data->wall_x * data->img_width);
			tex_y = (y - ceiling) * data->img_height / (floor - ceiling);
			pixel_addr = data->wall_data + (tex_y * data->img_width
				* (data->bits_per_pixel / 8)) + (tex_x * (data->bits_per_pixel / 8));
			data->wall_color = *(int *)pixel_addr;
			put_pixel_to_image(data, x, y, data->wall_color);

			// don't print pixel transparent 0xFF0000
			if ((unsigned int)data->wall_color != 0xFF0000)
			{
				put_pixel_to_image(data, x, y, data->wall_color);
			}
			x++;
		}
		y++;
	}
}

// void	render_textures_objects(int x, float distance_to_wall, t_data *data, float wall_x)
// {
// 	int	ceiling;
// 	int	floor;

// 	ceiling = (float)(S_H / 2.0) - (S_H / (float)distance_to_wall);
// 	floor = S_H - ceiling;
// 	if (data->is_door)
// 		data->wall_data = data->textures.door_data;
// 	data->wall_x = wall_x;
// 	render_object(x, ceiling, floor, data);
// }

void	render_textures(int x, float distance_to_wall, t_data *data, float wall_x)
{
    int ceiling;
    int floor;

    ceiling = (float)(S_H / 2.0) - (S_H / (float)distance_to_wall);
    floor = S_H - ceiling;
	if (data->is_door) 
    {
        data->wall_data = data->textures.door_data;
    }
	else
	{
		if (data->wall_type == 0 )
			data->wall_data = data->textures.no_data;
		else if (data->wall_type == 1 )
			data->wall_data = data->textures.ea_data;
		else if (data->wall_type == 2 )
			data->wall_data = data->textures.we_data;
		else if (data->wall_type == 3)
			data->wall_data = data->textures.so_data;
	}
    data->wall_x = wall_x;
    render_column(x, ceiling, floor, data);
}

// This function calculates the direction of the ray from the player's
// position. It determines the step direction (stepX, stepY)
// and the initial distances to the next X and Y grid lines 
// (side_distX, side_distY).
void	initialize_ray(t_player *player, t_rays *rays, float ray_angle)
{
	rays->ray_dirX = cosf(ray_angle);
	rays->ray_dirY = sinf(ray_angle);
	rays->delta_distX = fabsf(1 / rays->ray_dirX);
	rays->delta_distY = fabsf(1 / rays->ray_dirY);
	if (rays->ray_dirX < 0)
	{
		rays->stepX = -1;
		rays->side_distX = (player->playerX - (int)player->playerX) * rays->delta_distX;
	}
	else
	{
		rays->stepX = 1;
		rays->side_distX = ((int)player->playerX + 1.0 - player->playerX) * rays->delta_distX;
	}
	if (rays->ray_dirY < 0)
	{
		rays->stepY = -1;
		rays->side_distY = (player->playerY - (int)player->playerY) * rays->delta_distY;
	}
	else
	{
		rays->stepY = 1;
		rays->side_distY = ((int)player->playerY + 1.0 - player->playerY) * rays->delta_distY;
	}
}


void	perform_dda(t_rays *rays, t_data *data, bool *hit_wall)
{
	while (!*hit_wall)
	{
		if (rays->side_distX < rays->side_distY)
		{
			rays->side_distX += rays->delta_distX;
			rays->mapX += rays->stepX;
			rays->hit_side = 0; // Vertical wall
		}
		else
		{
			rays->side_distY += rays->delta_distY;
			rays->mapY += rays->stepY;
			rays->hit_side = 1; // Horizontal wall
		}
		if (data->map_two_d[rays->mapY][rays->mapX] == 'D')
		{
			*hit_wall = true;
			data->is_door = true;
		}
		if (data->map_two_d[rays->mapY][rays->mapX] == 'F')
		{
			*hit_wall = true;
			data->is_fire = true;
		}
		else if (data->map_two_d[rays->mapY][rays->mapX] == '1' || data->map_two_d[rays->mapY][rays->mapX] == 'D'
					|| data->map_two_d[rays->mapY][rays->mapX] == 'F')
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
float calculate_perpendicular_distance(t_rays *rays, t_player *player,
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

float	cast_rays(int x, t_player *player, t_data *data,float *wall_x)
{
	t_rays	rays;
	float	perp_wall_dist;
	float	ray_angle;
	bool	hit_wall;

	hit_wall = false;
	data->is_door = false; // Reset door flag for each ray
	data->is_fire = false;
	
	rays.mapX = (int)player->playerX;
	rays.mapY = (int)player->playerY;
	ray_angle = (player->playerA - player->FOV / 2.0f)
		+ ((float)x / (float)S_W) * player->FOV;
	initialize_ray(player, &rays, ray_angle);
	perform_dda(&rays, data, &hit_wall);
	perp_wall_dist = calculate_perpendicular_distance(&rays,
			player, wall_x, &data->wall_type);
	return (perp_wall_dist * cosf(ray_angle - player->playerA));
}

int	redraw_image(t_game *game)
{
	int		x;
	float	distance_to_wall;
	float	wall_x;

	x = 0;
	distance_to_wall = 0;
	wall_x = 0;
	game->data->wall_type = 0;
	game->data->img = mlx_new_image(game->mlx->mlx_p, S_W, S_H);
	game->data->img_data = mlx_get_data_addr(game->data->img,
			&game->data->bits_per_pixel,
			&game->data->size_line, &game->data->endian);
	while (x < S_W)
	{
		distance_to_wall = cast_rays(x, game->player,
				game->data, &wall_x);
		render_textures(x, distance_to_wall, game->data, wall_x);
		//render_textures_objects(x, distance_to_wall, game->data, wall_x);
		x += 2;
	}
	render_weapon(game->data);
	render_board(game->data);
	mlx_put_image_to_window(game->mlx->mlx_p, game->mlx->window,
		game->data->img, 0, 0);
	mlx_destroy_image(game->mlx->mlx_p, game->data->img);
	return (0);
}
