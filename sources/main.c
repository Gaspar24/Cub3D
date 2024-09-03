/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:10:46 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/03 17:42:22 by msacaliu         ###   ########.fr       */
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

void    startup(t_data *data, char *filename)
{
    char *full_path = ft_strjoin("./sources/maps/", filename);
    data->map2d = read_map(full_path);

    int i = 0;
    int j = 0;
    while(data->map2d[i])
    {
        j = 0;
        while (data->map2d[j])
        {
            printf("%c",data->map2d[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int main(int argc, char **argv)
{
    t_mlx    mlx;
    
    t_data data;
    (void)argc;

    startup(&data, argv[1]);
    // mlx.mlx_p = mlx_init();
    // mlx.window = mlx_new_window(mlx.mlx_p,1280,720,"Maze Runner");
    // mlx_loop(mlx.mlx_p);
    return(0);
}

