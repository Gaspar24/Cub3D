/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:10:46 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/03 13:18:05 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"




// void game_loop(void *ml) // game loop
// {
// 	t_mlx *mlx;

// 	mlx = ml; // cast to the mlx structure
// 	mlx_delete_image(mlx->mlx_p, mlx->img); // delete the image
// 	mlx->img = mlx_new_image(mlx->mlx_p, S_W, S_H); // create new image
// 	hook(mlx, 0, 0); // hook the player
// 	cast_rays(mlx); // cast the rays
// 	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0); // put the image to the window
// }

int main(int argc, char **argv)
{
    t_mlx    mlx;
    (void)argc;
    (void)argv;

    mlx.mlx_p = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx_p,1280,720,"Maze Runner");
    mlx_loop(mlx.mlx_p);
    return(0);
}

