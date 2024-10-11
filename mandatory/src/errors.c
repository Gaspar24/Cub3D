/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:51:36 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/03 15:51:36 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	exist_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void	invalid_char(t_data *data)
{
	int		y;
	int		x;
	char	current_char;

	y = 0;
	while (data->map_two_d[y] != NULL)
	{
		x = 0;
		while (data->map_two_d[y][x] != '\0')
		{
			current_char = data->map_two_d[y][x];
			if (!exist_player(current_char) && current_char != '1'
				&& current_char != '0' && current_char != ' '
				&& current_char != '\n' && current_char != '\r')
			{
				printf("❌ Invalid or hidden char in map_two_d"
					" at (%d, %d): %c (ASCII:%d)\n", y, x, current_char,
					current_char);
				exit_error(data, "");
			}
			x++;
		}
		y++;
	}
}

void	player_checks(t_data *data)
{
	int	y;
	int	flag_player;
	int	x;

	y = 0;
	flag_player = 0;
	while (data->map_two_d[y] != NULL)
	{
		x = 0;
		while (data->map_two_d[y][x] != '\0')
		{
			if (exist_player(data->map_two_d[y][x]))
			{
				flag_player++;
				data->player_x = x;
				data->player_y = y;
			}
			x++;
		}
		y++;
	}
	if (flag_player == 0)
		exit_error(data, "❌ Player not found inside map\n");
	if (flag_player > 1)
		exit_error(data, "❌ Too many players\n");
}

void	check_errors(t_data *data)
{
	
	invalid_char(data);
	player_checks(data);
}

void	check_all_paths(t_data *data)
{
	if (!data->no_path || !data->so_path || !data->we_path || !data->ea_path
		|| !data->ceiling_color || !data->floor_color)
	{
		printf("❌ Error: One or more texture paths in .cub are missing\n");
		exit(EXIT_FAILURE);
	}
}
