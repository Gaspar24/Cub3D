/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mapcheck                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:45:53 by pfalli            #+#    #+#             */
/*   Updated: 2024/09/13 15:45:53 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void set_path(char **str, const char *line)
{
    *str = ft_strdup(line + 3);
    (*str)[strlen(*str) - 2] = '\0';
    printf("%s\n", *str);
}

int parse_color(char *color_str)
{
    int r, g, b;

    ft_sscanf(color_str, "%d,%d,%d", &r, &g, &b);
	if (r < 0 || r > 250)
        {
            printf("❌ Error: Floor color value %d is out of range (0-250)\n", r);
            exit(EXIT_FAILURE);
        }
    return (r << 16) | (g << 8) | b;
}


void store_paths(t_data *data)
{
    int fd;
    char *line;

    fd = open(data->map_path, O_RDONLY);
    if (fd < 0)
        exit(1);
    while ((line = get_next_line(fd, 0)) != NULL)
    {
        if (ft_strncmp(line, "NO ", 3) == 0)
            set_path(&data->no_path, line);
        else if (ft_strncmp(line, "SO ", 3) == 0)
            set_path(&data->so_path, line);
        else if (ft_strncmp(line, "WE ", 3) == 0)
            set_path(&data->we_path, line);
        else if (ft_strncmp(line, "EA ", 3) == 0)
            set_path(&data->ea_path, line);
        else if (ft_strncmp(line, "F ", 2) == 0)
			data->floor_color = parse_color(line + 2);
		else if (ft_strncmp(line, "C ", 2) == 0)
			data->ceiling_color = parse_color(line + 2);
        free(line);
    }
    close(fd);
    get_next_line(fd, 1);
}

int count_map_lines(char **map_two_d)
{
    int count = 0;
    while (map_two_d[count] != NULL) {
        count++;
    }
    return count;
}


int calculate_lines_before_map(t_data *data)
{
    int fd;
    int lines = 0;
    char *line;

    fd = open(data->map_path, O_RDONLY);
    if (fd < 0)
    {
        printf("❌ Error: Map not found\n");
        exit(EXIT_FAILURE);
    }
    while ((line = get_next_line(fd, 0)) != NULL)
    {
        // Skip empty/whitespace lines
        if (line[0] == '\n' || line[0] == '\0' || ft_strspn(line, " \t\n") == ft_strlen(line))
        {
            free(line);
            lines++;
            continue;
        }
        // Check if the line is the start of the map
        if (is_map_line(line))
        {
            free(line);
            break;
        }
        lines++;
        free(line);
    }
    get_next_line(fd, 1); 
    return close(fd), lines;
}

int check_path(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if (str[i] == ' ')
            return (1);
        i++;
    }
    return(0);
}

void check_paths(t_data *data)
{
    if (check_path(data->no_path) == 1 || check_path(data->so_path) == 1 || check_path(data->we_path) == 1 || check_path(data->ea_path) == 1)
        exit_error(data, "❌ Error: texture path is invalid\n");
}

void parsing_map(t_data *data)
{
    int skip_lines = calculate_lines_before_map(data) + 1; // *** map not found ***
	store_paths(data);
	map_two_d(data, skip_lines);
	// debug_print_map(data);
	check_errors(data);
    if (data->map_two_d != NULL)
    {
        calculate_map_dimensions(data);
    }
	if (is_map_closed(data->map_two_d, data) == false)
        exit_error(data, "❌ Error: Map is not closed by 1\n");
    check_paths(data);
}


void map_two_d(t_data *data, int skip_lines)
{
    int fd;
    int i = 0;
    char *line;

    if (skip_lines == -1)
        exit(EXIT_FAILURE);
    fd = open(data->map_path, O_RDONLY);
    if (fd < 0)
        exit(EXIT_FAILURE);
    int j = 1;
    while (j < skip_lines)
    {
        line = get_next_line(fd, 0);
        if (line)
            free(line);
        j++;
    }
    data->map_two_d = malloc(sizeof(char *) * 500);
    if (!data->map_two_d)
        exit(EXIT_FAILURE);
    while ((line = get_next_line(fd, 0)) != NULL)
    {
        if (line[0] == '\n' || line[0] == '\0' || ft_strspn(line, " \t\n") == ft_strlen(line))
        {
            free(line);
            continue;
        }
        line[ft_strcspn(line, "\n")] = '\0'; // removes new_lines
        data->map_two_d[i++] = line;
    }
    data->map_two_d[i] = NULL;
    close(fd);
}
