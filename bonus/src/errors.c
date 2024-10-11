/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:52:37 by pfalli            #+#    #+#             */
/*   Updated: 2024/09/19 14:26:40 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool exist_player(char c)
{
    return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void invalid_char(t_data *data)
{
    int y = 0;
    while (data->map_two_d[y] != NULL)
    {
        int x = 0;
        while (data->map_two_d[y][x] != '\0')
        {
            char current_char = data->map_two_d[y][x];

            if (!exist_player(current_char) && current_char != '1' &&
                current_char != '0' && current_char != ' ' &&
                current_char != '\n' && current_char != '\r' && current_char != 'D' && current_char != 'F')
            {
				printf("❌ Invalid or hidden char in map at (%d, %d): %c (ASCII: %d)\n", y, x, current_char, current_char);
				exit_error(data, "");
            }
            x++;
        }
        y++;
    }
}
// check_colors is inside parse_color
void player_checks(t_data *data)
{
    int y = 0;
	int flag_player = 0;
    while (data->map_two_d[y] != NULL)
    {
        int x = 0;
        while (data->map_two_d[y][x] != '\0')
        {
            // if (data->map_two_d[y][x]== 'N' || data->map_two_d[y][x]== 'S' || data->map_two_d[y][x]== 'W' || data->map_two_d[y][x]== 'E')
			if (data->map_two_d[y][x]== 'N')
                flag_player++;  
            x++;
        }
        y++;
    }
	if (flag_player == 0)
		exit_error(data, "❌ Player not found inside map\n");
	if (flag_player > 1)
		exit_error(data, "❌ Too many players\n");
}


void check_errors(t_data *data)
{
	invalid_char(data);
	player_checks(data);
}