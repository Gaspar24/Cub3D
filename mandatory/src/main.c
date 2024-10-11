/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:02:56 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/03 14:02:56 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	startup(t_data *data, t_player **player, char *filename, t_mlx *mlx)
{
	data->map_path = ft_strdup(filename);
	if(check_map_format(data->map_path))
	{
		mlx_destroy_display(mlx->mlx_p);
		free(data->map_path);
		free(mlx->mlx_p);
		exit(1);
	}
	init_paths(data);
	parsing_map(data);
	*player = init_player(data);
	data->player = *player;
	init_keys(&(data->keys));
	load_textures(data, mlx);
}

int	update_player(t_game *game)
{
	update_player_position(game->player, &(game->data->keys), game->data);
	redraw_image(game);
	return (0);
}

void	game_loop(t_data *data, t_mlx *mlx, t_player *player)
{
	t_game	game;

	game.mlx = mlx;
	game.player = player;
	game.data = data;
	data->game = &game;
	mlx->window = mlx_new_window(mlx->mlx_p, S_W, S_H, "Maze Runner");
	mlx_hook(mlx->window, 2, 1L << 0, key_press, &game);
	mlx_hook(mlx->window, 3, 1L << 1, key_release, &game);
	mlx_hook(mlx->window, 17, 1L << 17, close_window, &game);
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
		printf("❌ Error, insert==> ./cub3d <map_path>");
		exit(EXIT_FAILURE);
	}
	mlx.mlx_p = mlx_init();
	data.mlx = &mlx;
	startup(&data, &player, argv[1], &mlx);
	game_loop(&data, &mlx, player);
	return (0);
}

// int main()
// {
// 	int fd = open("maps/wrong17.cub", O_RDONLY);
// 	char *line = get_next_line(fd, 0);
// 	printf("%s\n", line);
// 	free(line);
// 	line = get_next_line(fd, 0);
// 	printf("%s\n", line);
// 	free(line);
// 	return 0;

// }