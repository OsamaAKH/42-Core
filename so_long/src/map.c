/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:16:52 by okhan             #+#    #+#             */
/*   Updated: 2025/08/04 16:38:12 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_rectangular(t_game *game)
{
	int	i;
	int	first_line_len;

	if (!game->map.lines || !game->map.lines[0])
		ft_error_exit(game, "Empty map");
	first_line_len = ft_strlen(game->map.lines[0]);
	if (first_line_len == 0)
		ft_error_exit(game, "Empty map");
	i = 1;
	while (game->map.lines[i])
	{
		if ((int)ft_strlen(game->map.lines[i]) != first_line_len)
			ft_error_exit(game, "Map is not rectangular");
		i++;
	}
	game->map.rows = i;
	game->map.cols = first_line_len;
}

static void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if ((i == 0 || i == game->map.rows - 1)
				|| (j == 0 || j == game->map.cols - 1))
			{
				if (game->map.lines[i][j] != '1')
					ft_error_exit(game, "Map must be surrounded by walls");
			}
			j++;
		}
		i++;
	}
}

static void	count_elements(t_game *game, char c, int i, int j)
{
	if (c == 'P')
	{
		game->map.p++;
		game->player.actual.x = j;
		game->player.actual.y = i;
		game->map.lines[i][j] = '0';
	}
	else if (c == 'E')
		game->map.e++;
	else if (c == 'C')
		game->map.c++;
	else if (c != '0' && c != '1')
		ft_error_exit(game, "Invalid character in map");
}

static void	check_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			count_elements(game, game->map.lines[i][j], i, j);
			j++;
		}
		i++;
	}
	if (game->map.p != 1)
		ft_error_exit(game, "Map must contain exactly one player (P)");
	if (game->map.e != 1)
		ft_error_exit(game, "Map must contain exactly one exit (E)");
	if (game->map.c < 1)
		ft_error_exit(game, "Map must contain at least one collectible (C)");
}

void	validate_map(t_game *game)
{
	check_rectangular(game);
	if (game->map.rows < 3 || game->map.cols < 3)
		ft_error_exit(game, "Map must be at least 3x3");
	check_walls(game);
	check_characters(game);
	check_reachability(game);
}
