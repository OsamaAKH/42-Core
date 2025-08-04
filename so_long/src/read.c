/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:50:02 by okhan             #+#    #+#             */
/*   Updated: 2025/07/28 22:51:41 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	read_lines(t_game *game, char *filename, int count)
{
	int		fd;
	int		i;
	char	*line;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_exit("Failed to open map file");
	game->map.lines = malloc(sizeof(char *) * (count + 1));
	if (!game->map.lines)
		ft_error_exit("Malloc failed");
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map.lines[i++] = line;
	}
	game->map.lines[i] = NULL;
	close(fd);
}

void	read_map(t_game *game, char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_exit("Failed to open map file");
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	close(fd);
	if (count == 0)
		ft_error_exit("Empty map file");
	read_lines(game, filename, count);
}