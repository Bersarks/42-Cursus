/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:48:24 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/09 17:34:24 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "src/libraries/mlx/mlx.h"
# include "src/libraries/libft/libft.h"
# include "src/libraries/ft_printf/ft_printf.h"

# define MLX_SYNC_IMAGE_WRITABLE    1
# define MLX_SYNC_WIN_FLUSH_CMD     2
# define MLX_SYNC_WIN_CMD_COMPLETED 3

enum
{
	KEY_ESC = 53,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
};

typedef struct s_vars{
	void	*mlx;
	void	*win;
	void	*backgorund;
	void	*tree;
	void	*player;
	void	*exit;
	void	*apple;
	char	**map;
	int		c_count;
	int		p_count;
	int		e_count;
	int		player_x;
	int		player_y;
	int		moves;
	int		mapw;
	int		maph;
	int		img_width;
	int		img_height;
	int		end;
	int		god_mode;
}				t_vars;

char	**mapread(char *file);
int		map_check(t_vars *game);
int		draw(t_vars *game);
void	init(t_vars *game);
void	so_play(t_vars *game);
void	put_image(t_vars *game, void *image, int x, int y);
void	player_w(t_vars *game);
void	player_a(t_vars *game);
void	player_s(t_vars *game);
void	player_d(t_vars *game);
int		exit_game(t_vars *game);
#endif
