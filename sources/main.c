/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:10:46 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/14 15:11:40 by msacaliu         ###   ########.fr       */
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

#include "cub3d.h"

#define MAP_WIDTH 16
#define MAP_HEIGHT 16
#define S_W 1920    // Define screen width
#define S_H 1080  // Define screen height

// Define key states
int key_states[4] = {0, 0, 0, 0}; // W, A, S, D keys states

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
    "1111111111111111"};
float fplayerX = 10.0f;
float fplayerY = 10.0f;
float fplayerA = 0.0f;
float fFOV = 3.14159 / 4.0;
float depth = 16.0;

void game_loop(t_data *data, t_mlx *mlx);
void redraw_image(t_mlx *mlx);

void move_character()
{
    float moveSpeed = 0.1f;
    float turnSpeed = 0.05f;

    float nextX = fplayerX;
    float nextY = fplayerY;

    // Move forward (W key)
    if (key_states[0])
    {
        nextX += cosf(fplayerA) * moveSpeed;
        nextY += sinf(fplayerA) * moveSpeed;
    }
    // Move backward (S key)
    if (key_states[2])
    {
        nextX -= cosf(fplayerA) * moveSpeed;
        nextY -= sinf(fplayerA) * moveSpeed;
    }
    // Turn left (A key)
    if (key_states[1])
    {
        fplayerA -= turnSpeed;
    }
    // Turn right (D key)
    if (key_states[3])
    {
        fplayerA += turnSpeed;
    }

    // Check for wall collision before updating position
    if (map[(int)nextY][(int)nextX] != '1')
    {
        fplayerX = nextX;
        fplayerY = nextY;
    }
}

// Key press event handler
int key_press(int keysym, t_mlx *mlx)
{
    if (keysym == 65307) // Escape key
        close_window(mlx);
    if (keysym == 'w')
        key_states[0] = 1; // W key
    if (keysym == 'a')
        key_states[1] = 1; // A key
    if (keysym == 's')
        key_states[2] = 1; // S key
    if (keysym == 'd')
        key_states[3] = 1; // D key

    return (0);
}

// Key release event handler
int key_release(int keysym, t_mlx *mlx)
{
    if (keysym == 'w')
        key_states[0] = 0; // W key
    if (keysym == 'a')
        key_states[1] = 0; // A key
    if (keysym == 's')
        key_states[2] = 0; // S key
    if (keysym == 'd')
        key_states[3] = 0; // D key

    return (0);
}

// Update game frame continuously
int update_game(t_mlx *mlx)
{
    move_character();
    redraw_image(mlx);
    return (0);
}

void redraw_image(t_mlx *mlx)
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

    for (int x = 0; x < S_W; x++)
    {
        float ray_angle = (fplayerA - fFOV / 2.0f) + ((float)x / (float)S_W) * fFOV;
        float distance_to_wall = 0;
        bool hit_wall = false;
        float eyeX = sinf(ray_angle);
        float eyeY = cosf(ray_angle);

        while (!hit_wall && distance_to_wall < depth)
        {
            distance_to_wall += 0.1f;
            int testX = (int)(fplayerX + eyeX * distance_to_wall);
            int testY = (int)(fplayerY + eyeY * distance_to_wall);
            if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT)
            {
                hit_wall = true;
                distance_to_wall = depth;
            }
            else if (map[testY][testX] == '1')
            {
                hit_wall = true;
            }
        }
        int ceiling = (float)(S_H / 2.0) - S_H / (float)distance_to_wall;
        int floor = S_H - ceiling;

        for (int y = 0; y < S_H; y++)
        {
            if (y < ceiling)
                mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, 0x00FF00); // Ceiling color
            else if (y >= ceiling && y <= floor)
            {
                int tex_y = (y - ceiling) * img_height / (floor - ceiling);
                int color = *(int *)(wall_data + (tex_y * size_line + (x % img_width) * (bits_per_pixel / 8)));
                mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, color); // Wall color
            }
            else
                mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, 0x888888); // Floor color
        }
    }
}

void game_loop(t_data *data, t_mlx *mlx)
{
    (void)data;
    mlx->mlx_p = mlx_init();
    mlx->window = mlx_new_window(mlx->mlx_p, S_W, S_H, "Maze Runner");

    mlx_hook(mlx->window, 2, 1L << 0, key_press, mlx);    // Key press event
    mlx_hook(mlx->window, 3, 1L << 1, key_release, mlx);  // Key release event
    mlx_loop_hook(mlx->mlx_p, update_game, mlx);          // Continuous game update
    mlx_loop(mlx->mlx_p);
}

int main(int argc, char **argv)
{
    t_mlx mlx;
    t_data data;

    game_loop(&data, &mlx);
    return (0);
}



