/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:24:50 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/09 17:34:27 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	images(t_vars *game)
{
	game->backgorund = mlx_xpm_file_to_image
		(game->mlx, "assets/bground.xpm", &game->img_width, &game->img_height);
	game->apple = mlx_xpm_file_to_image
		(game->mlx, "assets/apple.xpm", &game->img_width, &game->img_height);
	game->player = mlx_xpm_file_to_image
		(game->mlx, "assets/P.xpm", &game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image
		(game->mlx, "assets/p1.xpm", &game->img_width, &game->img_height);
	game->tree = mlx_xpm_file_to_image
		(game->mlx, "assets/tree.xpm", &game->img_width, &game->img_height);
}

static void	window_size(t_vars *game)
{
	int	i;

	game->mapw = ft_strlen(game->map[0]) * 40;
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->maph = i * 40;
}

void	init(t_vars *game)
{
	game->mlx = mlx_init();
	window_size(game);
	game->win = mlx_new_window(game->mlx, game->mapw, game->maph, "So Long");
	game->end = 1;
	game->god_mode = 0;
	game->moves = 0;
	images(game);
	draw(game);
}
