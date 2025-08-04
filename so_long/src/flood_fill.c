/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:18:51 by okhan             #+#    #+#             */
/*   Updated: 2025/08/04 16:40:24 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	flood_fill_rec(char **map_copy, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map.cols || y >= game->map.rows)
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	map_copy[y][x] = 'V';
	flood_fill_rec(map_copy, x + 1, y, game);
	flood_fill_rec(map_copy, x - 1, y, game);
	flood_fill_rec(map_copy, x, y + 1, game);
	flood_fill_rec(map_copy, x, y - 1, game);
}

static char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!map_copy)
		ft_error_exit(game, "Malloc failed");
	i = 0;
	while (i < game->map.rows)
	{
		map_copy[i] = ft_strdup(game->map.lines[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			ft_error_exit(game, "Malloc failed");
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	exit_unreachable(t_game *game, char **map_copy, const char *msg)
{
	free_map_copy(map_copy, game->map.rows);
	ft_error_exit(game, msg);
}

static void	check_items_reachable(t_game *game, char **map_copy)
{
	int	i;
	int	j;
	int	collectibles_found;
	int	exit_found;

	collectibles_found = 0;
	exit_found = 0;
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.lines[i][j] == 'C' && map_copy[i][j] == 'V')
				collectibles_found++;
			if (game->map.lines[i][j] == 'E' && map_copy[i][j] == 'V')
				exit_found = 1;
			j++;
		}
		i++;
	}
	if (collectibles_found != game->map.c)
		exit_unreachable(game, map_copy, "Not all collectibles are reachable");
	if (!exit_found)
		exit_unreachable(game, map_copy, "Exit is not reachable");
}

void	check_reachability(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game);
	flood_fill_rec(map_copy, game->player.actual.x, game->player.actual.y, \
		game);
	check_items_reachable(game, map_copy);
	free_map_copy(map_copy, game->map.rows);
}
