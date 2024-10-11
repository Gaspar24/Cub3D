/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:11:39 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/07 15:08:18 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


int	open_map_file(t_data *data)
{
	int	fd;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
	{
		printf("❌ Error: Map not found\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	allocate_map_memory(t_data *data)
{
	data->map_two_d = malloc(sizeof(char *) * 500);
	if (!data->map_two_d)
	{
		// free(data->map_two_d);
		exit_error(data,"Memory alocated for map, failed");
		// exit(1);
	}
}

void	skip_lines_in_file(int fd, int skip_lines)
{
	int		j;
	char	*line;

	j = 0;
	while (j < skip_lines - 1)
	{
		line = get_next_line(fd, 0);
		if (line)
			free(line);
		j++;
	}
}
