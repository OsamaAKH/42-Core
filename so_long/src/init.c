/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:37:45 by okhan             #+#    #+#             */
/*   Updated: 2025/07/28 22:23:19 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	load_images(t_game *game)
{
	int	img_w;
	int	img_h;

	game->o = mlx_xpm_file_to_image(game->mlx, "textures/o.xpm", &img_w, &img_h);
	game->c = mlx_xpm_file_to_image(game->mlx, "textures/c.xpm", &img_w, &img_h);
	game->e = mlx_xpm_file_to_image(game->mlx, "textures/e.xpm", &img_w, &img_h);
	game->p = mlx_xpm_file_to_image(game->mlx, "textures/p.xpm", &img_w, &img_h);
	if (!game->o || !game->c || !game->e || !game->p)
		ft_error_exit("Failed to load one or more .xpm images");
}
