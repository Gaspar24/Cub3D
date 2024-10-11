/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:40:19 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/23 14:08:56 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int keysym, t_game *game)
{
	t_keys	*keys;

	keys = &(game->data->keys);
	if (keysym == KEY_W)
		keys->move_forward = 1;
	else if (keysym == KEY_S)
		keys->move_backward = 1;
	else if (keysym == KEY_A)
		keys->move_left = 1;
	else if (keysym == KEY_D)
		keys->move_right = 1;
	else if (keysym == KEY_LEFT)
		keys->turn_left = 1;
	else if (keysym == KEY_RIGHT)
		keys->turn_right = 1;
	else if (keysym == KEY_ESC)
	{
		close_window(game);
	}
	return (0);
}

int	key_release(int keysym, t_game *game)
{
	t_keys	*keys;

	keys = &(game->data->keys);
	if (keysym == KEY_W)
		keys->move_forward = 0;
	else if (keysym == KEY_S)
		keys->move_backward = 0;
	else if (keysym == KEY_A)
		keys->move_left = 0;
	else if (keysym == KEY_D)
		keys->move_right = 0;
	else if (keysym == KEY_LEFT)
		keys->turn_left = 0;
	else if (keysym == KEY_RIGHT)
		keys->turn_right = 0;
	return (0);
}
