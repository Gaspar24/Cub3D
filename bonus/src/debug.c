/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:18:00 by pfalli            #+#    #+#             */
/*   Updated: 2024/09/20 09:18:00 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void debug_print_wall_path(t_data *data)
{
	printf("%s", data->no_path);
	printf("%s", data->so_path);
	printf("%s", data->we_path);
	printf("%s", data->ea_path);
}

void debug_print_map(t_data *data)
{
    int i = 0;

    while (data->map_two_d[i] != NULL)
    {
        printf("%s\n", data->map_two_d[i]);
        i++;
    }
}

