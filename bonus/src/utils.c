/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:55:16 by pfalli            #+#    #+#             */
/*   Updated: 2024/09/13 15:55:16 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char **copy_map(char **map, int height)
{
    char **copy = malloc(sizeof(char *) * (height + 1));
    if (!copy)
        return NULL;

    int i = 0;
    while (i < height)
    {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i])
        {
            int j = 0;
            while (j < i)
            {
                free(copy[j]);
                j++;
            }
            free(copy);
            return NULL;
        }
        i++;
    }
    copy[height] = NULL;
    return copy;
}

void flood_fill(char **map_copy, int x, int y, t_data * data, bool *is_closed)
{
    if (x < 0 || y < 0 || y >= data->height || x >= ft_strlen(map_copy[y]))
    {
        *is_closed = false;
        return;
    }
    if (map_copy[y][x] == '1' || map_copy[y][x] == 'v')
        return;
    if (map_copy[y][x] == ' ') 
    {
        *is_closed = false;
        return;
    }
    map_copy[y][x] = 'v';
    flood_fill(map_copy, x + 1, y, data, is_closed);
    flood_fill(map_copy, x - 1, y, data, is_closed);
    flood_fill(map_copy, x, y + 1, data, is_closed);
    flood_fill(map_copy, x, y - 1, data, is_closed);
}

bool is_map_closed(char **map, t_data *data)
{
    bool is_closed = true;
    int y = 0;

	char **map_copy = copy_map(data->map_two_d, data->height);
    if (!map_copy)
    {
        printf("Error: Failed to copy map\n");
        exit(EXIT_FAILURE);
    }
    // Find the first empty space to start the flood fill
    while (y < data->height)
    {
        int x = 0;
        while (x < ft_strlen(map_copy[y]))
        {
            if (map[y][x] == '0')
            {
                flood_fill(map_copy, x, y, data, &is_closed);
                break;
            }
            x++;
        }
        if (!is_closed)
            break;
        y++;
    }
	int i = 0; // *** free_map(map_copy) ***
	while (i < data->height)
    {
        free(map_copy[i]);
        i++;
    }
    free(map_copy);
    return is_closed;
}

int ft_strspn(const char *str, const char *accept)
{
    int count = 0;
    while (str[count]) {
        const char *a = accept;
        while (*a) {
            if (str[count] == *a)
                break;
            a++;
        }
        if (*a == '\0')
            break;
        count++;
    }
    return count;
}

char *ft_strtok(char *str, const char *delim) 
{
    static char *current;
    char *token_start;

    if (str != NULL)
        current = str;
    if (current == NULL)
        return NULL;
    while (*current && ft_strrchr(delim, *current))
        current++;
    if (*current == '\0')
        return NULL;
    token_start = current;
    while (*current && !ft_strrchr(delim, *current))
        current++;
    if (*current)
    {
        *current = '\0';
        current++;
    }
    else
        current = NULL;
    return token_start;
}

// get the colors and store them
int ft_sscanf(const char *str, const char *format, int *r, int *g, int *b)
{
    char *temp_str;
    char *token;

    if (strcmp(format, "%d,%d,%d") != 0)
        return -1;
    temp_str = ft_strdup(str);
    CHECK_NULL_AND_RETURN(temp_str);

    token = ft_strtok(temp_str, ",");
    CHECK_NULL_AND_RETURN(token);
    *r = ft_atoi(token);

    token = ft_strtok(NULL, ",");
    CHECK_NULL_AND_RETURN(token);
    *g = ft_atoi(token);

    token = ft_strtok(NULL, ",");
    CHECK_NULL_AND_RETURN(token);
    *b = ft_atoi(token);

    free(temp_str);
    return 3;
}

int is_map_line(const char *line)
{
    // Skip leading whitespace
    while (isspace(*line))
    {
        //printf("SKIPPED: Line '%s' is an empty line.\n", line);
        line++;
    }

    // Check if the line starts with a configuration keyword
    if (strncmp(line, "NO ", 3) == 0 || strncmp(line, "SO ", 3) == 0 ||
        strncmp(line, "WE ", 3) == 0 || strncmp(line, "EA ", 3) == 0 ||
        strncmp(line, "F ", 2) == 0 || strncmp(line, "C ", 2) == 0)
    {
        //printf("SKIPPED: Line '%s' is a configuration line.\n", line);
        return 0;
    }

    // Check if the line contains at least 5 '1' characters
    int count = 0;
    //const char *original_line = line;
    while (*line)
    {
        if (*line == '1')
        {
            count++;
        }
        line++;
    }
    //printf("FOUND IT! Line '%s' has %d '1' characters.\n", original_line, count);
    return count >= 5; // it found at least 5 '1'
}

size_t ft_strcspn(const char *s, const char *reject)
{
    size_t count = 0;

    while (*s) {
        const char *r = reject;
        while (*r) {
            if (*s == *r) {
                return count;
            }
            r++;
        }
        s++;
        count++;
    }
    return count;
}



