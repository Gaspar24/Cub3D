/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:12:55 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/07 12:12:55 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	parse_color(char *color_str)
{
	t_rgb	rgb;

	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	
	check_color_string(color_str);
	ft_sscanf(color_str, "%d,%d,%d", &rgb);
	if (rgb.r < 0 || rgb.r > 255)
		return (1);
	if (rgb.g < 0 || rgb.g > 255)
		return (1);
	if (rgb.b < 0 || rgb.b > 255)
		return (1);
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}



void	store_paths(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		line = trim_line(line);
		if (ft_strncmp(line, "NO ", 2) == 0)
		{
			if(data->no_path == NULL)
				data->no_path = ft_strdup(line + 2);
		}
		else if (ft_strncmp(line, "SO ", 2) == 0)
		{
			if(data->so_path == NULL)
				data->so_path = ft_strdup(line + 2);
		}
			
		else if (ft_strncmp(line, "WE ", 2) == 0)
		{
			if(data->we_path == NULL)
				data->we_path = ft_strdup(line + 2);
		}
		else if (ft_strncmp(line, "EA ", 2) == 0)
		{
			if(data->ea_path == NULL)
				data->ea_path = ft_strdup(line + 2);
		}
		else if (ft_strncmp(line, "F ", 1) == 0)
			data->floor_color = parse_color(line + 1);
		else if (ft_strncmp(line, "C ", 1) == 0)
			data->ceiling_color = parse_color(line + 1);
		free(line);
		line = get_next_line(fd, 0);
		
	}
	// free(line);
	close(fd);
	get_next_line(fd, 1);
	// return()
}

int	calculate_lines_before_map(t_data *data)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open_map_file(data);
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		if (is_empty_or_whitespace_line(line))
		{
			free(line);
			count++;
			line = get_next_line(fd, 0);
			continue ;
		}
		if (is_map_line(line))
		{
			free(line);
			break ;
		}
		count++;
		free(line);
		line = get_next_line(fd, 0);
	}
	return (close(fd), get_next_line(fd, 1), count);
}

bool is_map_empty(t_data *data)
{
	int		fd;
	char	*line;
	bool	empty;

	empty = true;
	fd = open(data->map_path, O_RDONLY);
	line = get_next_line(fd, 0);
	int i = 0;
	while (line != NULL)
	{
		if(i > 1000)
		{
			free(line);
			exit_before_window_open(data,"Map has to many lines");
		}
		i++;
		line = trim_line(line);
		if (!ft_strncmp(line, "NO", 2))
			empty = false;
		else if (!ft_strncmp(line, "SO", 2))
			empty = false;
		else if (!ft_strncmp(line, "WE", 2))
			empty = false;
		else if (!ft_strncmp(line, "EA", 2))
			empty = false;
		else if (!ft_strncmp(line, "F", 1))
			empty = false;
		else if (!ft_strncmp(line, "C", 1))
			empty = false;
		else if (!ft_strncmp(line, "111", 3))
			empty = false;
		free(line);
		line = get_next_line(fd, 0);
	}
	if(line)
		free(line);
	close(fd);
	get_next_line(fd, 1);
	return(empty);
}



void	exit_before_window_open(t_data *data, char *str)
{
		printf("❌ERROR %s\n",str);
		free(data->map_path);
		mlx_destroy_display(data->mlx->mlx_p);
		free(data->mlx->mlx_p);
		exit(1);
}

void	check_if_all_paths_exist(t_data *data)
{
	if(!data->no_path || !data->so_path || !data->we_path || !data->ea_path)
	{
		if (data->no_path != NULL)
			free(data->no_path);
		if (data->so_path != NULL)
			free(data->so_path);
		if (data->we_path != NULL)
			free(data->we_path);
		if (data->ea_path != NULL)
			free(data->ea_path);
		exit_before_window_open(data,"one of the paths is missing");
	}
		
}

void	parsing_map(t_data *data)
{
	int	skip_lines;
	int	fd;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		exit_before_window_open(data," Map not found or cannot open");
	if (is_map_empty(data) == true)
		exit_before_window_open(data,"Map/texture/colors missing");
	skip_lines = calculate_lines_before_map(data) + 1;
	store_paths(data);
	check_if_all_paths_exist(data);
	map_two_d(data, skip_lines);
	calculate_map_dimensions(data);
	check_errors(data);
	replace_hiddenchars_with_spaces(data->map_two_d, data->height);
	replace(data->map_two_d, data->height);
	check_first_line(data);
	is_map_closed(data->map_two_d, data);
	map_is_last(data); // open map, i have to free
}

int	map_two_d(t_data *data, int skip_lines)
{
	int		fd;
	int		i;
	char	*line;
	int count = 0;

	i = 0;
	if (skip_lines == -1)
		exit(EXIT_FAILURE);
	fd = open_map_file(data);
	skip_lines_in_file(fd, skip_lines);
	allocate_map_memory(data);
	line = get_next_line(fd, 0);
	while (line != NULL && count < 1001)
	{
		count++;
		printf("%d\n", count);
		if (is_empty_or_whitespace_line(line))
		{
			free(line);
			
			line = get_next_line(fd, 0);
			continue ;
		}
		line[ft_strcspn(line, "\n")] = '\0';
		data->map_two_d[i++] = line;
		line = get_next_line(fd, 0);
	}
	free(line);
	data->map_two_d[i] = NULL;
	return (close(fd), get_next_line(fd, 1), 0);
}
