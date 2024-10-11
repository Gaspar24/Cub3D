/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:02:00 by msacaliu          #+#    #+#             */
/*   Updated: 2024/10/01 15:38:28 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_forward_and_backwards(t_player *player, t_keys *keys, t_data *data)
{
	float	move_step;
	float	new_player_x;
	float	new_player_y;

	move_step = 0;
	if (keys->move_forward)
		move_step = player->move_speed;
	else if (keys->move_backward)
		move_step = -player->move_speed;
	new_player_x = player->playerX + cosf(player->playerA) * move_step;
	new_player_y = player->playerY + sinf(player->playerA) * move_step;
	if (data->map_two_d[(int)new_player_y][(int)new_player_x] != '1')
	{
		player->playerX = new_player_x;
		player->playerY = new_player_y;
	}
}

void	move_left_and_right(t_player *player, t_keys *keys, t_data *data)
{
	float	move_step;
	float	new_player_x;
	float	new_player_y;

	move_step = 0;
	if (keys->move_right)
		move_step = player->move_speed;
	else if (keys->move_left)
		move_step = -player->move_speed;
	new_player_x = player->playerX - sinf(player->playerA) * move_step;
	new_player_y = player->playerY + cosf(player->playerA) * move_step;
	if (data->map_two_d[(int)new_player_y][(int)new_player_x] != '1')
	{
		player->playerX = new_player_x;
		player->playerY = new_player_y;
	}
}

void	rotate_player(t_player *player, t_keys *keys)
{
	if (keys->turn_left)
	{
		player->playerA -= player->turn_speed;
		if (player->playerA < 0)
			player->playerA += 2 * M_PI;
	}
	if (keys->turn_right)
	{
		player->playerA += player->turn_speed;
		if (player->playerA > 2 * M_PI)
			player->playerA -= 2 * M_PI;
	}
}

void	update_player_position(t_player *player, t_keys *keys, t_data *data)
{
	move_forward_and_backwards(player, keys, data);
	move_left_and_right(player, keys, data);
	rotate_player(player, keys);
}
