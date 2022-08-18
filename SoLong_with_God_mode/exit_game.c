/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:21:26 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/07 10:24:09 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_vars *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->backgorund);
	mlx_destroy_image(game->mlx, game->tree);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->apple);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}
