/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:37:40 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/08 15:52:46 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_map_line(const char *line)
{
	int	count;

	count = 0;
	while (ft_isspace(*line))
	{
		line++;
	}
	if (new_strncmp(line, "NO ", 2) == 0 || new_strncmp(line, "SO ", 2) == 0
		|| new_strncmp(line, "WE ", 2) == 0 || new_strncmp(line, "EA ", 2) == 0
		|| new_strncmp(line, "F ", 1) == 0 || new_strncmp(line, "C ", 1) == 0)
	{
		return (0);
	}
	while (*line)
	{
		if (*line == '1')
		{
			count++;
		}
		line++;
	}
	return (count >= 3);
}

int	new_strncmp(const char *s1, const char *s2, int n)
{
	while (n > 0)
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int	is_empty_or_whitespace_line(const char *line)
{
	if(line[0] == '\n' || line[0] == '\0' || ft_strspn(line, " \t\n") == ft_strlen(line))
		return(true);
	return false;
}

void	check_first_line(t_data *data)
{
	int	i;

	i = 0;
	printf("data->map_two_d[0]: %s\n", data->map_two_d[0]);
	while (data->map_two_d[0][i] != '\0')
	{
		if (data->map_two_d[0][i] != '1' && data->map_two_d[0][i] != 'X' && data->map_two_d[0][i] != 13)
		{
			exit_error(data, "❌ Error: Map is invalid first line\n");
		}
		i++;
	}
}

void	replace_hiddenchars_with_spaces(char **map, int height)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < ft_strlen(map[y]))
		{
			if (map[y][x] == 13)
			{
				map[y][x] = ' ';
			}
			x++;
		}
		y++;
	}
}
