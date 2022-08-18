/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:05:04 by otokluog          #+#    #+#             */
/*   Updated: 2022/07/04 17:34:04 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_w(t_vars *game)
{
	if (game->map[game->player_y][game->player_x] == 'E'
			&& game->c_count == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y + 1][game->player_x] = '0';
		game->moves++;
		game->end = 0;
		draw(game);
		exit_game(game);
	}
	else if ((game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'E')
		&& game->god_mode == 0)
		game->player_y += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->c_count -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y + 1][game->player_x] = '0';
		game->moves++;
		draw(game);
	}
}

void	player_a(t_vars *game)
{
	if (game->map[game->player_y][game->player_x] == 'E' && game->c_count == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y][game->player_x + 1] = '0';
		game->moves++;
		game->end = 0;
		draw(game);
		exit_game(game);
	}
	else if ((game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'E')
		&& (game->god_mode == 0))
		game->player_x += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->c_count -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x + 1] = '0';
		game->moves++;
		draw(game);
	}
}

void	player_s(t_vars *game)
{
	if (game->map[game->player_y][game->player_x] == 'E' && game->c_count == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y - 1][game->player_x] = '0';
		game->moves++;
		game->end = 0;
		draw(game);
		exit_game(game);
	}
	else if ((game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'E')
		&& game->god_mode == 0)
		game->player_y -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->c_count -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y - 1][game->player_x] = '0';
		game->moves++;
		draw(game);
	}
}

void	player_d(t_vars *game)
{
	if (game->map[game->player_y][game->player_x] == 'E' && game->c_count == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y][game->player_x - 1] = '0';
		game->moves++;
		game->end = 0;
		draw(game);
		exit_game(game);
	}
	else if ((game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'E')
		&& game->god_mode == 0)
			game->player_x -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->c_count -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x - 1] = '0';
		game->moves++;
		draw(game);
	}
}
