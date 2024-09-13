/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:37:05 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/13 15:23:21 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// test code------------------

// void	move_character(int keysym)
// {
// 	//handle rotation
// 	if(keysym == 'a')
// 	{
// 		fplayerA -= (0.2f);
// 	}
// 	if(keysym == 'd')
// 	{
// 		fplayerA += (0.2f);
// 	}
// }


// int	handle_input(int keysym, t_mlx *mlx)
// {
// 	if (keysym == 65307)
// 	{
// 		close_window(mlx);
// 	}
// 	if (keysym == 'w' || keysym == 's' || keysym == 'a' || keysym == 'd')
// 		move_character(keysym);
// 	return (0);
// }



/// my code---------------
// int	handle_input(int keysym, t_mlx *mlx)
// {
// 	if (keysym == 65307)
// 	{
// 		close_window(mlx);
// 	}
// 	if (keysym == 'w' || keysym == 's' || keysym == 'a' || keysym == 'd')
// 		move_character(keysym, data);
// 	return (0);
// }

void	close_window(t_mlx *mlx)
{
	printf("GAME OVER!\n");
	mlx_destroy_window(mlx->mlx_p, mlx->window);
	mlx_destroy_display(mlx->mlx_p);
	exit(1);

}