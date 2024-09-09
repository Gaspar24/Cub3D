/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:10:46 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/09 14:41:30 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    startup(t_data *data, char *filename)
{
    char *full_path = ft_strjoin("./sources/maps/", filename);
	full_path = ft_strjoin(full_path, ".cub");
    data->map2d = read_map(full_path, data);

}


// // int main(int argc, char **argv)
// // {
// //     t_mlx    mlx;
// //     t_data data;
    
// //     if(argc != 2)
// //     {
// //         printf("Error\n");
// //         exit(1);
// //     }

// //     // int		img_width = 550;
// // 	// int		img_height = 550;

// //     startup(&data, argv[1]);
// //     mlx.mlx_p = mlx_init();
// //     mlx.window = mlx_new_window(mlx.mlx_p,1920,1080,"Maze Runner");
// //     // mlx.img = mlx_xpm_file_to_image(mlx.mlx_p,"./sources/textures/floor.xpm", &img_height, &img_height);
// //     // mlx_put_image_to_window(mlx.mlx_p,mlx.window, mlx.img, 150,150);
// //     draw_wall(&data, 50,50,&mlx);
// //     // draw_floor(&data, 50,50,&mlx);

// //     // if(mlx.img==NULL)
// //     //     exit(1);
// //     mlx_loop(mlx.mlx_p);
// //     return(0);
// // }


// /// --------------test main + raycast--------------------





int main(int argc, char **argv)
{
    t_mlx    mlx;
    t_data data;
    
    if(argc != 2)
    {
        printf("Error\n");
        exit(1);
    }
    startup(&data, argv[1]);
	

    mlx.mlx_p = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx_p,1920,1080,"Maze Runner");
	mlx_key_hook(mlx.window, handle_input, &mlx);

    mlx_loop(mlx.mlx_p);
    return(0);
}



