/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:36:46 by okhan             #+#    #+#             */
/*   Updated: 2025/07/29 00:52:23 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.cols)
		return (0);
	if (new_y < 0 || new_y >= game->map.rows)
		return (0);
	if (game->map.lines[new_y][new_x] == '1')
		return (0);
	return (1);
}

static void	handle_collectible(t_game *game, int new_x, int new_y)
{
	if (game->map.lines[new_y][new_x] == 'C')
	{
		game->player.c++;
		game->map.lines[new_y][new_x] = '0';
	}
}

static void	handle_exit(t_game *game, int new_x, int new_y)
{
	if (game->map.lines[new_y][new_x] == 'E')
	{
		if (game->player.c == game->map.c)
		{
			ft_printf("You won in %d moves!\n", game->player.moves + 1);
			close_window(game);
		}
		return ;
	}
	game->map.lines[game->player.actual.y][game->player.actual.x] = '0';
	game->map.lines[new_y][new_x] = 'P';
	game->player.actual.x = new_x;
	game->player.actual.y = new_y;
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;

	new_x = game->player.actual.x + dx;
	new_y = game->player.actual.y + dy;
	if (!is_valid_move(game, new_x, new_y))
		return ;
	handle_collectible(game, new_x, new_y);
	handle_exit(game, new_x, new_y);
	game->player.moves++;
	ft_printf("Moves: %d\n", game->player.moves);
	render_map(game);
}
