/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:10:03 by pfalli            #+#    #+#             */
/*   Updated: 2024/09/13 13:10:03 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	startup(t_data *data, t_player **player, char *filename, t_mlx *mlx)
{
	data->map_path = ft_strdup(filename);
	parsing_map(data);
	*player = init_player(data);
    init_keys(&(data->keys));
    load_textures(data, mlx);
    calculate_map_dimensions(data);
}

int	update_player(t_game *game)
{
	update_player_position(game->player, &(game->data->keys),game->data);
	redraw_image(game);
	mini_map(game->data, game->mlx, game->player);
	return (0);
}


void	game_loop(t_data *data, t_mlx *mlx, t_player *player)
{
	t_game	game;

	game.mlx = mlx;
	game.player = player;
	game.data = data;
	game.player->lastX = S_W / 2;

	mlx->window = mlx_new_window(mlx->mlx_p, S_W, S_H, "Maze Runner");
	mlx_hook(mlx->window, 2, 1L << 0, key_press, &game);
	mlx_hook(mlx->window, 3, 1L << 1, key_release, &game);
	mlx_hook(mlx->window, 17, 1L << 17, close_window, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, mouse_move, &game);
	mlx_loop_hook(mlx->mlx_p, update_player, &game);
	mlx_loop(mlx->mlx_p);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_data		data;
	t_player	*player;

    if (argc != 2)
    {
        printf("❌ Error, insert==> ./cub3d <map_path>" ORANGE " (ex: ./cub3d maps/valid.ber)\n" RESET);
        exit(EXIT_FAILURE);
    }
    mlx.mlx_p = mlx_init();
    startup(&data, &player, argv[1], &mlx);
    game_loop(&data,&mlx,player);
    return(0);
}
