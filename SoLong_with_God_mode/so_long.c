/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:20:17 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/07 11:00:00 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	av_check(char *av)
{
	int	i;

	if (!av)
		return (0);
	i = 0;
	while (av[i])
		i++;
	i -= 1;
	if (av[i] == 'r' && av[i - 1] == 'e' && av[i - 2] == 'b'
		&& av[i - 3] == '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	game;

	if (ac == 2)
	{
		game.map = mapread(av[1]);
		if (map_check(&game) && av_check(av[1]))
		{
			init(&game);
			so_play(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (!game.map)
				free(game.map);
			exit_game(&game);
		}
	}
	return (0);
}
