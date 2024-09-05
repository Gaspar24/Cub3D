/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:10:39 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/05 16:18:03 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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


char  *assign_coordinates(char *coordinate, char *buffer)
{
	coordinate = malloc(strlen(buffer + 2) + 1);
	if (coordinate == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if(buffer[0] == 'F' || buffer[0] == 'C')
		coordinate = ft_strcpy(coordinate, buffer + 1);
	else
		coordinate = ft_strcpy(coordinate, buffer + 2);
	return(coordinate);
}

void	get_coordinates(int fd, t_data *data)
{
	char	buffer[MAX_LINE_LENGTH + 1];
	int		i;
	ssize_t	n;
	
	i = 0;
	n = read(fd, &buffer[i], 1); 
	while(n > 0)
	{
		if(buffer[i] == '\n' || i == MAX_LINE_LENGTH -1)
		{
			buffer[i+1] ='\0'; // null terminate after the next line  || may be problem if max line reached 
			if(buffer[0] == 'N' && buffer[1] == 'O')
				data->NO = assign_coordinates(data->NO, buffer);
			if(buffer[0] == 'S' && buffer[1] == 'O')
				data->SO = assign_coordinates(data->SO, buffer);
			if(buffer[0] == 'W' && buffer[1] == 'E')
				data->WE = assign_coordinates(data->WE, buffer);
			if(buffer[0] == 'E' && buffer[1] == 'A')
				data->EA = assign_coordinates(data->EA, buffer);
			// if(buffer[0] == 'F')
			// 	printf("---%s", buffer + 1);
			// if(buffer[0] == 'C')
			// 	printf("---%s", buffer+1);
			i = 0;
		}
		else
			i++;
		n = read(fd, &buffer[i], 1);
	}
	// if(i > 0)
	// 		printf("%s", buffer); // last row
}


char	**fill_map(int fd, char **map)
{

	char	buffer[MAX_LINE_LENGTH + 1];
	int		i;
	int		j;
	ssize_t	n;

	i = 0;
	j = 0;
	n = read(fd, &buffer[i], 1); 

	while(n > 0)
	{
		if(buffer[i] == '\n' || i == MAX_LINE_LENGTH -1)
		{
			buffer[i + 1] = '\0';
			if (buffer[0] == '1')
			{
				map[j] = ft_strcpy(map[j], buffer);
				j++;
			}
                 // Print the buffer if it starts with '1'
			i = 0;
		}
		else
			i++;
		n = read(fd, &buffer[i], 1);
	}
	if (i > 0)
    {
		buffer[i] = '\n';
		buffer[i+1] = '\0';
		if (buffer[0] == '1')
		{
			map[j] = ft_strcpy(map[j], buffer);
			j++;
		}
	}
	map[j] = NULL;
	return(map);
}




char	**read_map(const char *filename, t_data *data)
{
	int		fd;
	// char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open file\n");
		exit(1);
	}
	data->map2d = init_map();
	// fill_map(fd, map);
	data->map2d = fill_map(fd,data->map2d);
	get_coordinates(fd, data);
	close(fd);
	return (data->map2d);
}