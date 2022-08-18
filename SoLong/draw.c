/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:20:12 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/07 11:38:06 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_vars *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 40, y * 40);
}

static void	player_draw(t_vars *game, void *image, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	put_image(game, image, x, y);
}

static void	draw_exit(t_vars *game, int x, int y)
{
	if (game->c_count == 0)
	{
		mlx_destroy_image(game->mlx, game->exit);
		game->exit = mlx_xpm_file_to_image
			(game->mlx, "assets/p2.xpm", &game->img_width, &game->img_height);
	}
	put_image(game, game->exit, x, y);
}

static void	background_draw(t_vars *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_image(game, game->backgorund, x, y);
			x++;
		}
		y++;
	}
}

int	draw(t_vars *game)
{
	int	x;
	int	y;

	background_draw(game);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				put_image(game, game->tree, x, y);
			else if (game->map[y][x] == 'P')
				player_draw(game, game->player, x, y);
			else if (game->map[y][x] == 'C')
				put_image(game, game->apple, x, y);
			else if (game->map[y][x] == 'E')
				draw_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
