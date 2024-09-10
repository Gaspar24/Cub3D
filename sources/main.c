/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:10:46 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/10 15:04:11 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    startup(t_data *data, char *filename)
{
    char *full_path = ft_strjoin("./sources/maps/", filename);
	full_path = ft_strjoin(full_path, ".cub");
    data->map2d = read_map(full_path, data);

}


void    game_loop(t_data *data, t_mlx *mlx)
{
    mlx->mlx_p = mlx_init();
    mlx->window = mlx_new_window(mlx->mlx_p,1920,1080,"Maze Runner");
    draw_wall(data,50,50,mlx);
    // draw_floor(data,50,50, mlx);
	mlx_key_hook(mlx->window, handle_input, mlx);

    mlx_loop(mlx->mlx_p);
}


int main(int argc, char **argv)
{
    t_mlx    mlx;
    t_data data;
    
    if(argc != 2)
    {
        printf("Error\n");
        printf("Wrong number of arguments");
        exit(1);
    }
    startup(&data, argv[1]);
    game_loop(&data, &mlx);
    return(0);
}


// ---------------------------tutorial test--------------------

// ----------Global vars---------


// int map_width = 16;
// int map_height = 16;
// char map[16][16] = {
//     "1111111111111111",
//     "1000000000000001",
//     "1000000000000001",
//     "1000000000000001",
//     "1000000000000001",
//     "1000000000000001",
//     "1000000000000001",
//     "1000000000000001",
//     "1000000000000001",
//     "1000000000000001",
//     "1000000000000001",
//     "1000000000000001",
//     "1000000000000001",
//     "1000000000000001",
//     "1000000000000001",
//     "1111111111111111"
// };

// float fPlayerX = 8.0f; // Start position in the middle of the map
// float fPlayerY = 8.0f; // Start position in the middle of the map
// float fPlayerA = 0.0f; // Initial view angle
// int screen_width = 1280;
// int screen_height = 720;

// float fov = 3.14159f / 4.0f;
// float depth = 16.0f;

// // Movement parameters
// int key_states[256] = {0}; // Array to track which keys are pressed

// // typedef struct s_mlx {
// //     void    *mlx_p;
// //     void    *window;
// //     struct {
// //         void *img;
// //         char *addr;
// //         int bits_per_pixel;
// //         int line_length;
// //         int endian;
// //     } img;
// // } t_mlx;

// // Function to track key press events
// int key_press(int keycode, t_mlx *mlx) {
//     key_states[keycode] = 1; // Set key as pressed
//     return 0;
// }

// // Function to track key release events
// int key_release(int keycode, t_mlx *mlx) {
//     key_states[keycode] = 0; // Set key as released
//     return 0;
// }

// // Function to update player movement based on pressed keys
// void update_player_movement() {
//     float move_speed = 0.1f;
//     float rotate_speed = 0.1f;

//     if (key_states[13]) { // W: Move forward
//         fPlayerX += cosf(fPlayerA) * move_speed;
//         fPlayerY += sinf(fPlayerA) * move_speed;
//     }
//     if (key_states[1]) { // S: Move backward
//         fPlayerX -= cosf(fPlayerA) * move_speed;
//         fPlayerY -= sinf(fPlayerA) * move_speed;
//     }
//     if (key_states[0]) { // A: Strafe left
//         fPlayerX += cosf(fPlayerA - 3.14159f / 2) * move_speed;
//         fPlayerY += sinf(fPlayerA - 3.14159f / 2) * move_speed;
//     }
//     if (key_states[2]) { // D: Strafe right
//         fPlayerX += cosf(fPlayerA + 3.14159f / 2) * move_speed;
//         fPlayerY += sinf(fPlayerA + 3.14159f / 2) * move_speed;
//     }
//     if (key_states[123]) { // Left arrow: Rotate left
//         fPlayerA -= rotate_speed;
//     }
//     if (key_states[124]) { // Right arrow: Rotate right
//         fPlayerA += rotate_speed;
//     }
// }

// // Helper function to put pixel
// void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color) {
//     char *dst;
//     dst = mlx->img.addr + (y * mlx->img.line_length + x * (mlx->img.bits_per_pixel / 8));
//     *(unsigned int *)dst = color;
// }

// // Game loop function
// void game_loop(t_data *data, t_mlx *mlx) {
//     // Initialize mlx and create window first
//     mlx->mlx_p = mlx_init();
//     mlx->window = mlx_new_window(mlx->mlx_p, screen_width, screen_height, "Maze Runner");

//     // Create image after initializing mlx
//     mlx->img.img = mlx_new_image(mlx->mlx_p, screen_width, screen_height);
//     mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);

//     // Hook for key press and release
//     mlx_hook(mlx->window, 2, 1L<<0, key_press, mlx);    // Key press
//     mlx_hook(mlx->window, 3, 1L<<1, key_release, mlx);  // Key release

//     // Main rendering loop
//     while (1) {
//         // Update player movement based on keys pressed
//         update_player_movement();

//         // Clear the image by re-rendering the scene
//         for (int x = 0; x < screen_width; x++) {
//             // Calculate the ray angle
//             float ray_angle = (fPlayerA - fov / 2.0f) + ((float)x / (float)screen_width) * fov;
//             float distance_to_wall = 0;
//             bool hit_wall = false;

//             // Ray unit vector
//             float EyeX = sinf(ray_angle);
//             float EyeY = cosf(ray_angle);

//             // Raycasting: check for wall hit
//             while (!hit_wall && distance_to_wall < depth) {
//                 distance_to_wall += 0.1f;
//                 int testX = (int)(fPlayerX + EyeX * distance_to_wall);
//                 int testY = (int)(fPlayerY + EyeY * distance_to_wall);

//                 // Test if ray is out of bounds
//                 if (testX < 0 || testX >= map_width || testY < 0 || testY >= map_height) {
//                     hit_wall = true;
//                     distance_to_wall = depth;
//                 } else {
//                     // Ray is in bounds, check for a wall
//                     if (map[testY][testX] == '1') {
//                         hit_wall = true;
//                     }
//                 }
//             }

//             // Calculate the ceiling and floor positions
//             int ceiling = (int)(screen_height / 2.0f - screen_height / (float)distance_to_wall);
//             int floor = screen_height - ceiling;

//             // Draw the vertical slice (ceiling, wall, and floor)
//             for (int y = 0; y < screen_height; y++) {
//                 if (y < ceiling) {
//                     my_mlx_pixel_put(mlx, x, y, 0x87CEEB); // Ceiling color (light blue)
//                 } else if (y > ceiling && y <= floor) {
//                     // Ensure shading does not go out of bounds
//                     float shade = 1.0f - (distance_to_wall / depth); // Darken based on distance
//                     shade = fmaxf(0.0f, fminf(1.0f, shade)); // Clamp between 0 and 1
//                     int wall_color = (int)(shade * 255);
//                     my_mlx_pixel_put(mlx, x, y, (wall_color << 16) | (wall_color << 8) | wall_color); // Grayscale wall
//                 } else {
//                     my_mlx_pixel_put(mlx, x, y, 0x008000); // Floor color (green)
//                 }
//             }
//         }

//         // After rendering all the columns, put the image to the window
//         mlx_put_image_to_window(mlx->mlx_p, mlx->window, mlx->img.img, 0, 0);
//     }

//     // Start the mlx loop to handle input, etc.
//     mlx_loop(mlx->mlx_p);
// }

// int main(int argc, char **argv) {
//     t_mlx mlx;
//     t_data data;

//     // Start the game loop
//     game_loop(&data, &mlx);
//     return 0;
// }