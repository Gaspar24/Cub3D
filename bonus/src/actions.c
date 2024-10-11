/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:40:19 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/26 14:20:37 by pfalli           ###   ########.fr       */
/*   Updated: 2024/09/23 14:08:56 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	load_door_texture(t_data *data, t_mlx *mlx, char c)
{
	if (c == 'o')
	{
		data->textures.door = mlx_xpm_file_to_image(mlx->mlx_p, "./textures/objects/open_64.xpm",
	            &data->img_width, &data->img_height);
    }
    else
	{
		 data->textures.door = mlx_xpm_file_to_image(mlx->mlx_p, "./textures/objects/door_64.xpm",
	            &data->img_width, &data->img_height);
	}
	if (!data->textures.door)
	    error("Error loading door texture");
	data->textures.door_data = mlx_get_data_addr(data->textures.door,
	        &data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.door_data)
	    error("Error getting data address for foor texture");
    data->entered_trough_door = false;
}


void	load_weapon_texture(t_data *data, t_mlx *mlx, char c)
{
    char *str;

    if(c == 'a')
        str = "./textures/weapon/axe.xpm";
    else
        str = "./textures/weapon/halo.xpm";

    data->textures.weapon = mlx_xpm_file_to_image(mlx->mlx_p, str,
	            &data->img_width, &data->img_height);
	if (!data->textures.weapon)
	    error("Error loading axe texture");
	data->textures.weapon_data = mlx_get_data_addr(data->textures.weapon,
	        &data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->textures.axe_data)
	    error("Error getting data address for weapon texture");    
}


int key_press(int keycode, t_game *game)
{
    t_keys *keys = &(game->data->keys); 
    if (keycode == KEY_W)
        keys->move_forward = 1;
    else if (keycode == KEY_S)
        keys->move_backward = 1;
    else if (keycode == KEY_A)
        keys->move_left = 1;
    else if (keycode == KEY_D)
        keys->move_right = 1;
    else if (keycode == KEY_LEFT)
        keys->turn_left = 1;
    else if (keycode == KEY_RIGHT)
        keys->turn_right = 1;
    else if (keycode == KEY_E)
    {
        game->data->is_open_door = true;
        load_door_texture(game->data, game->mlx, 'o');
    }
    else if (keycode == KEY_Q)
    {
        game->data->is_open_door = false;
        load_door_texture(game->data, game->mlx,'c');
    }
    else if (keycode == KEY_F1) {
        // game->textures.weapon_data = game->textures.weapon_data;
        load_weapon_texture(game->data, game->mlx,'g');
        sleep(0.1);
        printf("Weapon changed to gun\n");
    }
    else if (keycode == KEY_F2)
    {
        load_weapon_texture(game->data, game->mlx,'a');

        sleep(0.1);
        printf("Weapon changed to axe\n");
    }
    else if (keycode == KEY_ESC)
        close_window(game->data, game->mlx);
    if(game->data->entered_trough_door == true)
        close_window(game->data, game->mlx);

    return (0);
}

int key_release(int keycode, t_game *game)
{
    t_keys *keys = &(game->data->keys);
    // Update the movement states based on key release
    if (keycode == KEY_W)
        keys->move_forward = 0;
    else if (keycode == KEY_S)
        keys->move_backward = 0;
    else if (keycode == KEY_A)
        keys->move_left = 0;
    else if (keycode == KEY_D)
        keys->move_right = 0;
    else if (keycode == KEY_LEFT)
        keys->turn_left = 0;
    else if (keycode == KEY_RIGHT)
        keys->turn_right = 0;
    return (0);
}
