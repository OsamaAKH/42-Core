/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:24:09 by okhan             #+#    #+#             */
/*   Updated: 2025/08/04 17:42:42 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>

# define TILE_SIZE 32
# define BUFFER_SIZE 42

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_player
{
	int		c;
	int		moves;
	t_xy	attempt;
	t_xy	actual;
}	t_player;

typedef struct s_map
{
	int		rows;
	int		cols;
	int		c;
	int		e;
	int		p;
	int		diff_cols;
	int		px;
	char	**lines;
}	t_map;

typedef struct s_game
{
	void		*o;
	void		*c;
	void		*e;
	void		*p;
	void		*floor;
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
}	t_game;

void	ft_error_exit(t_game *game, const char *msg);
int		close_window(t_game *game);
int		key_hook(int keycode, t_game *game);
void	read_map(t_game *game, char *filename);
void	check_reachability(t_game *game);
void	validate_map(t_game *game);
void	render_map(t_game *game);
void	load_images(t_game *game);
void	move_player(t_game *game, int dx, int dy);
void	free_map(char **map);
char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strdup_gnl(const char *src);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_find_newline(const char *str);
void	free_map_copy(char **map_copy, int rows);
void	render_tile(t_game *game, char tile, int x, int y);

#endif
