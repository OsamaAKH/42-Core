/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:52:37 by okhan             #+#    #+#             */
/*   Updated: 2025/08/04 14:45:13 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_exit(t_game *game, char *msg)
{
	if (game && game->map.lines)
		free_map(game->map.lines);
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

int	close_window(t_game *game)
{
	if (game->map.lines)
		free_map(game->map.lines);
	if (game->o)
		mlx_destroy_image(game->mlx, game->o);
	if (game->c)
		mlx_destroy_image(game->mlx, game->c);
	if (game->e)
		mlx_destroy_image(game->mlx, game->e);
	if (game->p)
		mlx_destroy_image(game->mlx, game->p);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_window(game);
	else if (keycode == XK_w)
		move_player(game, 0, -1);
	else if (keycode == XK_s)
		move_player(game, 0, 1);
	else if (keycode == XK_a)
		move_player(game, -1, 0);
	else if (keycode == XK_d)
		move_player(game, 1, 0);
	return (0);
}

static void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->o = NULL;
	game->c = NULL;
	game->e = NULL;
	game->p = NULL;
	game->map.lines = NULL;
	game->lines = NULL;
	game->map.p = 0;
	game->map.e = 0;
	game->map.c = 0;
	game->player.moves = 0;
	game->player.c = 0;
	game->player.actual.x = -1;
	game->player.actual.y = -1;
}

static void	validate_args(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		ft_error_exit("Usage: ./so_long <map.ber>");
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
		ft_error_exit("Map file must have .ber extension");
}

int	main(int argc, char **argv)
{
	t_game	game;

	validate_args(argc, argv);
	init_game(&game);
	read_map(&game, argv[1]);
	validate_map(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_error_exit("MiniLibX init failed");
	game.win = mlx_new_window(game.mlx, game.map.cols * TILE_SIZE,
			game.map.rows * TILE_SIZE, "so_long");
	if (!game.win)
		ft_error_exit("Window creation failed");
	load_images(&game);
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}