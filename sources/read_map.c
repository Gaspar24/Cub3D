/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:10:39 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/03 18:02:48 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**init_map(void)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(MAX_LINES * sizeof(char *));
	while (i < MAX_LINES)
	{
		map[i] = malloc((MAX_LINE_LENGTH + 1) * sizeof(char));
		if (!map[i])
		{
			while (i >= 0)
				free(map[i--]);
			free(map);
			printf("Failed to allocate memory\n");
			exit(1);
		}
		i++;
	}
	return (map);
}

void	fill_map(int fd, char **map)
{
	char	buffer[MAX_LINE_LENGTH + 1];
	int		i[2];
	ssize_t	n;

	i[X] = 0;
	i[Y] = 0;
	n = read(fd, &buffer[i[Y]], 1); 
	while (n > 0)
	{
        // while(buffer[i[0]] != '1')
        //     i[Y]++;
		if (buffer[i[Y]] == '\n' || i[Y] == MAX_LINE_LENGTH - 1)
		{
			buffer[i[Y]] = '\0';
			ft_strcpy(map[i[X]++], buffer);
			i[Y] = 0;
		}
		else
			i[Y]++;
		n = read(fd, &buffer[i[Y]], 1);
	}
	if (i[Y] > 0)
	{
		buffer[i[Y]] = '\0';
		ft_strcpy(map[i[X]++], buffer);
	}
	map[i[X]] = NULL;
}

char	**read_map(const char *filename)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open file\n");
		exit(1);
	}
	map = init_map();
	fill_map(fd, map);
	close(fd);
	return (map);
}