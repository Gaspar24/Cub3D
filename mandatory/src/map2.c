/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:58:23 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/03 14:06:59 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	count_map_lines(char **map_two_d)
{
	int	count;

	count = 0;
	while (map_two_d[count] != NULL)
	{
		count++;
	}
	return (count);
}

char	*trim_line(char *line)
{
	line = trim_char(line, ' ');
	line = trim_char(line, 13);
	line = trim_char(line, 10);
	line = trim_char(line, 9);
	return (line);
}

void	calculate_map_dimensions(t_data *data)
{
	int	height;
	int	width;
	int	current_width;

	height = 0;
	width = 0;
	while (data->map_two_d[height] != NULL)
	{
		current_width = ft_strlen(data->map_two_d[height]);
		if (current_width > width)
		{
			width = current_width;
		}
		height++;
	}
	data->height = height;
	data->width = width;
}

int	is_valid_map_line(char *line)
{
	return (ft_strncmp(line, "NO", 2) == 0
		|| ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0
		|| ft_strncmp(line, "F", 1) == 0
		|| ft_strncmp(line, "C", 1) == 0);
}

int	map_is_last(t_data *data)
{
	int		fd;
	char	*line;
	int		map_started;

	map_started = 0;
	fd = open_map_file(data);
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		line = trim_line(line);
		if (ft_strncmp(line, "111", 3) == 0)
		{
			// printf("found!\n");
			map_started = 1;
		}
		if (map_started == 1 && is_valid_map_line(line))
		{
			free(line);
			print_error("❌ Error: Map is not last element in file");
		}
		free(line);
		line = get_next_line(fd, 0);
	}
	free(line);
	return (get_next_line(fd, 1), close(fd), 0);
}
