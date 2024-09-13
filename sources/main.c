/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:10:46 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/13 15:45:36 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    startup(t_data *data, char *filename)
// {
//     char *full_path = ft_strjoin("./sources/maps/", filename);
// 	full_path = ft_strjoin(full_path, ".cub");
//     data->map2d = read_map(full_path, data);

// }


// void    game_loop(t_data *data, t_mlx *mlx)
// {
//     mlx->mlx_p = mlx_init();
//     mlx->window = mlx_new_window(mlx->mlx_p,1920,1080,"Maze Runner");
//     draw_wall(data,50,50,mlx);
//     // draw_floor(data,50,50, mlx);
// 	mlx_key_hook(mlx->window, handle_input, mlx);

//     mlx_loop(mlx->mlx_p);
// }


// int main(int argc, char **argv)
// {
//     t_mlx    mlx;
//     t_data data;
    
//     if(argc != 2)
//     {
//         printf("Error\n");
//         printf("Wrong number of arguments");
//         exit(1);
//     }
//     startup(&data, argv[1]);
//     game_loop(&data, &mlx);
//     return(0);
// }

///test---------------

#define MAP_WIDTH 16
#define MAP_HEIGHT 16
# define S_W 1280 // Define screen width
# define S_H 720 // Define screen height

char map[MAP_HEIGHT][MAP_WIDTH + 1] = {
    "1111111111111111",
    "1000000000000001",
    "1000000000000001",
    "1000000000000001",
    "1000001100000001",
    "1000000000000001",
    "1000000000000001",
    "1000000000000001",
    "1000000000000001",
    "1000000000000001",
    "1000000000000001",
    "1000000000000001",
    "1000000000000001",
    "1000000000000001",
    "1000000000000001",
    "1111111111111111"
};
float fplayerX = 10.0f;
float fplayerY = 10.0f;
float fplayerA = 0.0f;
float fFOV = 3.14159 / 4.0;
float depth = 16.0;

void game_loop(t_data *data, t_mlx *mlx);
void    redraw_image(t_mlx *mlx);


void move_character(int keysym)
{
    if (keysym == 'w')
    {
        fplayerX += cosf(fplayerA) * 0.2f;
        fplayerY += sinf(fplayerA) * 0.2f;
    }
    if (keysym == 's')
    {
        fplayerX -= cosf(fplayerA) * 0.2f;
        fplayerY -= sinf(fplayerA) * 0.2f;
    }
    if (keysym == 'a')
    {
        fplayerA -= 0.1f;
    }
    if (keysym == 'd')
    {
        fplayerA += 0.1f;
    }
}

int handle_input(int keysym, t_mlx *mlx)
{
    if (keysym == 65307) // Escape key
    {
        close_window(mlx);
    }
    if (keysym == 'w' || keysym == 's' || keysym == 'a' || keysym == 'd')
    {
        move_character(keysym);
        redraw_image(mlx);
    }
    return (0);
}

void    redraw_image(t_mlx *mlx)
{
    int img_width, img_height;
    void *wall_img = mlx_xpm_file_to_image(mlx->mlx_p, "./sources/textures/wall.xpm", &img_width, &img_height);
    if (!wall_img)
    {
        fprintf(stderr, "Failed to load wall image\n");
        return;
    }

    // Get the image data
    int bits_per_pixel, size_line, endian;
    char *wall_data = mlx_get_data_addr(wall_img, &bits_per_pixel, &size_line, &endian);

    mlx_key_hook(mlx->window, handle_input, mlx);

    for (int x = 0; x < S_W; x++)
    {
        // For each column calculate the projected ray angle 
        float ray_angle = (fplayerA - fFOV / 2.0f) + ((float)x / (float)S_W) * fFOV;
        float distance_to_wall = 0;
        bool hit_wall = false;
        // Unit vector for ray in player pos
        float eyeX = sinf(ray_angle);
        float eyeY = cosf(ray_angle);

        while (!hit_wall && distance_to_wall < depth)
        {
            distance_to_wall += 0.1f;
            
            int testX = (int)(fplayerX + eyeX * distance_to_wall);
            int testY = (int)(fplayerY + eyeY * distance_to_wall);
            // Test if ray is out of bounds
            if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT)
            {
                hit_wall = true;
                distance_to_wall = depth;
            }
            else
            {
                // Ray is in bounds so test to see if the ray cell is a wall
                if (map[testY][testX] == '1')
                {
                    hit_wall = true;
                }
            }
        }
        // Calculate distance to ceiling and floor
        int ceiling = (float)(S_H / 2.0) - S_H / (float)distance_to_wall;
        int floor = S_H - ceiling;

        // Draw the column: ceiling, wall, floor
        for (int y = 0; y < S_H; y++)
        {
            if (y < ceiling)
            {
                // Draw ceiling (you can set it to a specific color, e.g., 0xCCCCCC for gray)
                mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, 0x00FF00);
            } 
            else if (y >= ceiling && y <= floor)
            {
                // Draw wall using the XPM image
                int tex_y = (y - ceiling) * img_height / (floor - ceiling);
                int color = *(int *)(wall_data + (tex_y * size_line + (x % img_width) * (bits_per_pixel / 8)));
                mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, color); // Wall color
            }
            else
            {
                // Draw floor (set a different color for the floor, e.g., 0x888888 for dark gray)
                mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, 0x888888); // Floor color
            }
        }
    }
}

void game_loop(t_data *data, t_mlx *mlx)
{
    (void)data;
    mlx->mlx_p = mlx_init();
    mlx->window = mlx_new_window(mlx->mlx_p, S_W, S_H, "Maze Runner");

    // Load the XPM image
    int img_width, img_height;
    void *wall_img = mlx_xpm_file_to_image(mlx->mlx_p, "./sources/textures/wall.xpm", &img_width, &img_height);
    if (!wall_img)
    {
        fprintf(stderr, "Failed to load wall image\n");
        return;
    }

    // Get the image data
    int bits_per_pixel, size_line, endian;
    char *wall_data = mlx_get_data_addr(wall_img, &bits_per_pixel, &size_line, &endian);

    mlx_key_hook(mlx->window, handle_input, mlx);

    for (int x = 0; x < S_W; x++)
    {
        // For each column calculate the projected ray angle 
        float ray_angle = (fplayerA - fFOV / 2.0f) + ((float)x / (float)S_W) * fFOV;
        float distance_to_wall = 0;
        bool hit_wall = false;
        // Unit vector for ray in player pos
        float eyeX = sinf(ray_angle);
        float eyeY = cosf(ray_angle);

        while (!hit_wall && distance_to_wall < depth)
        {
            distance_to_wall += 0.1f;
            
            int testX = (int)(fplayerX + eyeX * distance_to_wall);
            int testY = (int)(fplayerY + eyeY * distance_to_wall);
            // Test if ray is out of bounds
            if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT)
            {
                hit_wall = true;
                distance_to_wall = depth;
            }
            else
            {
                // Ray is in bounds so test to see if the ray cell is a wall
                if (map[testY][testX] == '1')
                {
                    hit_wall = true;
                }
            }
        }
        // Calculate distance to ceiling and floor
        int ceiling = (float)(S_H / 2.0) - S_H / (float)distance_to_wall;
        int floor = S_H - ceiling;

        // Draw the column: ceiling, wall, floor
        for (int y = 0; y < S_H; y++)
        {
            if (y < ceiling)
            {
                // Draw ceiling (you can set it to a specific color, e.g., 0xCCCCCC for gray)
                mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, 0x00FF00);
            } 
            else if (y >= ceiling && y <= floor)
            {
                // Draw wall using the XPM image
                int tex_y = (y - ceiling) * img_height / (floor - ceiling);
                int color = *(int *)(wall_data + (tex_y * size_line + (x % img_width) * (bits_per_pixel / 8)));
                mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, color); // Wall color
            }
            else
            {
                // Draw floor (set a different color for the floor, e.g., 0x888888 for dark gray)
                mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, 0x888888); // Floor color
            }
        }
    }
    mlx_loop(mlx->mlx_p);
}

int main(int argc, char **argv)
{
    t_mlx    mlx;
    t_data data;
    
    game_loop(&data, &mlx);
    return(0);
}



