/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:11:04 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/09 17:34:13 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	events(int keycode, t_vars *game)
{
	if (keycode == KEY_W)
	{
		game->player_y -= 1;
		player_w(game);
	}
	else if (keycode == KEY_A)
	{
		game->player_x -= 1;
		player_a(game);
	}
	else if (keycode == KEY_D)
	{
		game->player_x += 1;
		player_d(game);
	}
	else if (keycode == KEY_S)
	{
		game->player_y += 1;
		player_s(game);
	}
	else if (keycode == 5)
	{
		if (game->god_mode == 0)
			game->god_mode = 1;
		else
			game->god_mode = 0;
	}
}

int	keypress(int keycode, t_vars *game)
{
	if (keycode == KEY_ESC || game->end == 0)
		exit_game(game);
	if (game->end != 0)
	{
		events(keycode, game);
	}
	ft_printf("Move Count -> %d\n", game->moves);
	return (0);
}

void	so_play(t_vars *game)
{
	mlx_hook(game->win, 2, 0, keypress, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
}
