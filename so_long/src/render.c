/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:37:14 by okhan             #+#    #+#             */
/*   Updated: 2025/08/04 17:31:40 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	draw_tile(t_game *game, void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '0')
		draw_tile(game, game->floor, x, y);
	else if (tile == '1')
		draw_tile(game, game->o, x, y);
	else if (tile == 'C')
		draw_tile(game, game->c, x, y);
	else if (tile == 'E')
		draw_tile(game, game->e, x, y);
	else if (tile == 'P')
		draw_tile(game, game->p, x, y);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			tile = game->map.lines[y][x];
			render_tile(game, tile, x, y);
			if (x == game->player.actual.x && y == game->player.actual.y)
				draw_tile(game, game->p, x, y);
			x++;
		}
		y++;
	}
}
