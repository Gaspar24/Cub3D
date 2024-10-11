/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:21:39 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/07 12:21:39 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	debug_print_wall_path(t_data *data)
{
	printf("%s\n", data->no_path);
	printf("%s\n", data->so_path);
	printf("%s\n", data->we_path);
	printf("%s\n", data->ea_path);
}

void	debug_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

char	*trim_char(char *str, char ch)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	len = strlen(str);
	new_str = malloc(len + 1);
	if (!new_str)
		exit(EXIT_FAILURE);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i] != ch)
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

void	debug_print_asci_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		printf("%c: %d\n", str[i], str[i]);
		i++;
	}
}
