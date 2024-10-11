/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:42:06 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/23 14:15:03 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_paths(t_data *data)
{
	data->no_path = NULL;
	data->so_path = NULL;
	data->ea_path = NULL;
	data->we_path = NULL;
}

int	get_player_position(t_data *data, char c)
{
	int	y;
	int	x;

	y = 0;
	while (data->map_two_d[y] != NULL)
	{
		x = 0;
		while (data->map_two_d[y][x] != '\0')
		{
			if (exist_player(data->map_two_d[y][x]))
			{
				if (c == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char	get_player_orientation(t_data *data) /// Should work
{
	int	y;
	int	x;

	y = 0;
	while (data->map_two_d[y] != NULL)
	{
		x = 0;
		while (data->map_two_d[y][x] != '\0')
		{
			if (data->map_two_d[y][x] == 'N')
				return ('N');
			else if (data->map_two_d[y][x] == 'S')
				return ('S');
			else if (data->map_two_d[y][x] == 'E')
				return ('E');
			else if (data->map_two_d[y][x] == 'W')
				return ('W');
			x++;
		}
		y++;
	}
	return ('N');
}

t_player	*init_player(t_data *data)
{
	t_player	*player;
	char		orientation;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	orientation = get_player_orientation(data);
	if (orientation == 'N')
		player->playerA = 4.699998f;
	if (orientation == 'S')
		player->playerA = 1.566823f;
	if (orientation == 'E')
		player->playerA = 6.260009f;
	if (orientation == 'W')
	{
		player->playerA = 3.049994f;
	}
	player->playerX = (float)get_player_position(data, 'x');
	player->playerY = (float)get_player_position(data, 'y');
	player->FOV = 3.14159 / 4;
	player->depth = data->height;
	player->move_speed = 0.08;
	player->turn_speed = 0.04f;
	data->player = player;
	return (player);
}

void	init_keys(t_keys *keys)
{
	keys->move_forward = 0;
	keys->move_backward = 0;
	keys->move_left = 0;
	keys->move_right = 0;
	keys->turn_left = 0;
	keys->turn_right = 0;
}
