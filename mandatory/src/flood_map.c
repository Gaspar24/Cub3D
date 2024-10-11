/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:09:50 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/03 12:09:50 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


void	free_map_copy_2(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		map = NULL;
	}
}

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			j = 0;
			while (j < i)
			{
				free(copy[j]);
				j++;
			}
			return (free(copy), NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	replace(char **map, int height)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < ft_strlen(map[y]))
		{
			if (map[y][x] != '1' && map[y][x] != '0' && !exist_player(map[y][x]))
			{
				map[y][x] = 'X';
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(char **map_copy, int y, int x, t_data *data)
{
	// bool start_from_player = false;
	// if(exist_player(map_copy[y][x]))
	// 	start_from_player = true;
	
	if (y >= data->height ||x >= (int)ft_strlen(map_copy[y]) || x < 0 || map_copy[y][x] == ' ' || map_copy[y][x] == '\0' || map_copy[y][x] == 'X' )
	{
		free_map_copy_2(map_copy);
		// if(start_from_player)
		// 	exit_error(data, "❌ Error: player outside\n");
		exit_error(data, "❌ Error: map is invalid\n");
	}
	if (x < 0 || y < 0 || map_copy[y][x] == '1' || map_copy[y][x] == 'v')
	{
		return ;
	}
	map_copy[y][x] = 'v';
	flood_fill(map_copy, y - 1, x, data);
	flood_fill(map_copy, y + 1, x, data);
	flood_fill(map_copy, y, x - 1, data);
	flood_fill(map_copy, y, x + 1, data);
}

bool	check_map_closed(char **map, char **map_copy, t_data *data,
		bool *is_closed)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < ft_strlen(map_copy[y]))
		{
			data->flood_x = x;
			data->flood_y = y;
			if (map[data->flood_y][data->flood_x] == '0' || exist_player(map[data->flood_y][data->flood_x]) )
			{
				flood_fill(map_copy, y, x, data);
			}
			x++;
		}
		y++;
	}
	// while(map_copy)
	return (*is_closed);
}

bool	is_map_closed(char **map, t_data *data)
{
	bool	is_closed;
	char	**map_copy;

	is_closed = true;
	map_copy = copy_map(data->map_two_d, data->height);
	if (!map_copy)
		exit_error(data, "is_map_closed, not copied map");
	is_closed = check_map_closed(map, map_copy, data, &is_closed);
	// free_map_copy(map_copy, data->height);
	free_map_copy_2(map_copy);

	return (is_closed);
}

int	ft_sscanf(const char *str, const char *format, t_rgb *rgb)
{
	char	*temp_str;
	char	*token;

	if (strcmp(format, "%d,%d,%d") != 0)
		return (-1);
	temp_str = ft_strdup(str);
	if (check_null_and_return(temp_str) == -1)
	{
		free(temp_str);
		return (-1);
	}
		
	token = ft_strtok(temp_str, ",");
	if (check_null_and_return(token) == -1)
	{
		free(temp_str);
		return (-1);
	}
	rgb->r = ft_atoi(token);
	token = ft_strtok(NULL, ",");
	if (check_null_and_return(token) == -1)
	{
		free(temp_str);
		return (-1);
	}
	rgb->g = ft_atoi(token);
	token = ft_strtok(NULL, ",");
	if (check_null_and_return(token) == -1)
	{
		free(temp_str);
		return (-1);
	}
	rgb->b = ft_atoi(token);
	free(temp_str);
	return (3);
}
