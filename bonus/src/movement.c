/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:02:00 by msacaliu          #+#    #+#             */
/*   Updated: 2024/10/04 15:13:44 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_if_enterd_door(t_data *data, float new_playerX, float new_playerY)
{
	if (data->map_two_d[(int)new_playerY][(int)new_playerX] == 'D' && data->is_open_door)
	{
		data->entered_trough_door = true;
	}
}


int	mouse_move(int x, int y, t_game *game)
{
	(void)y;
	game->player->turn_speed = 0.01;
	if (x > game->player->lastX)
	{
		game->player->playerA += game->player->turn_speed;
		if (game->player->playerA > 2 * M_PI)
			game->player->playerA -= 2 * M_PI;
	}
	else if (x < game->player->lastX)
	{
		game->player->playerA -= game->player->turn_speed;
		if (game->player->playerA < 0)
			game->player->playerA += 2 * M_PI;
	}
	game->player->lastX = x;
	return (0);
}

void	move_forward_and_backwards(t_player *player, t_keys *keys, t_data *data)
{
	float	move_step;
	float	new_playerX;
	float	new_playerY;

	move_step = 0;
	if (keys->move_forward)
		move_step = player->move_speed;
	else if (keys->move_backward)
		move_step = -player->move_speed;
	new_playerX = player->playerX + cosf(player->playerA) * move_step;
	new_playerY = player->playerY + sinf(player->playerA) * move_step;
	if(data->map_two_d[(int)new_playerY][(int)new_playerX] == 'D' && data->is_open_door)
	{
		player->playerX = new_playerX;
		player->playerY = new_playerY;
	}
	else if (data->map_two_d[(int)new_playerY][(int)new_playerX] != '1' && data->map_two_d[(int)new_playerY][(int)new_playerX] != 'D')
	{
		player->playerX = new_playerX;
		player->playerY = new_playerY;
	}
	check_if_enterd_door(data, new_playerX, new_playerY);
}

void	move_left_and_right(t_player *player, t_keys *keys, t_data *data)
{
	float	new_playerX;
	float	new_playerY;

	new_playerX = 0;
	new_playerY = 0;
	if (keys->move_right)
	{
		new_playerX = player->playerX - sinf(player->playerA) * player->move_speed;
		new_playerY = player->playerY + cosf(player->playerA) * player->move_speed;
		if (data->map_two_d[(int)new_playerY][(int)new_playerX] != '1')
		{
			player->playerX = new_playerX;
			player->playerY = new_playerY;
		}
	}
	if (keys->move_left)
	{
		new_playerX = player->playerX + sinf(player->playerA) * player->move_speed;
		new_playerY = player->playerY - cosf(player->playerA) * player->move_speed;
		if (data->map_two_d[(int)new_playerY][(int)new_playerX] != '1')
		{
			player->playerX = new_playerX;
			player->playerY = new_playerY;
		}
	}
	check_if_enterd_door(data, new_playerX, new_playerY);

}

void	rotate_player(t_player *player, t_keys *keys)
{
	if (keys->turn_left)
	{
		player->playerA -= player->turn_speed; // Rotate left
		if (player->playerA < 0) 
			player->playerA += 2 * M_PI; // Ensure angle stays within 0 to 2π range
	}
	if (keys->turn_right)
	{
		player->playerA += player->turn_speed; // Rotate right
		if (player->playerA > 2 * M_PI) 
			player->playerA -= 2 * M_PI; // Ensure angle stays within 0 to 2π range
	}
}

void	update_player_position(t_player *player, t_keys *keys, t_data *data)
{
	move_forward_and_backwards(player, keys, data);
	move_left_and_right(player, keys, data);
	rotate_player(player, keys);
}
