/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:37:14 by okhan             #+#    #+#             */
/*   Updated: 2025/07/29 00:57:37 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	draw_tile(t_game *game, void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img,
			x * TILE_SIZE, y * TILE_SIZE);
}

static void	clear_tile(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;

	pixel_x = x * TILE_SIZE;
	pixel_y = y * TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx_pixel_put(game->mlx, game->win, pixel_x + j, pixel_y + i, 0x000000);
			j++;
		}
		i++;
	}
}

static void	render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '0')
		clear_tile(game, x, y);
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
			x++;
		}
		y++;
	}
}
