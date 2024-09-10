/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:37:05 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/10 15:04:20 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(int keysym, t_mlx *mlx)
{
	if (keysym == 65307)
	{
		close_window(mlx);
	}
	// if (keysym == 'w' || keysym == 's' || keysym == 'a' || keysym == 'd')
	// 	move_character(keysym, data);
	return (0);
}

void	close_window(t_mlx *mlx)
{
	printf("GAME OVER!\n");
	mlx_destroy_window(mlx->mlx_p, mlx->window);
	mlx_destroy_display(mlx->mlx_p);
	exit(1);

}