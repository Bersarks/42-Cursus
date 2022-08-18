/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:20:17 by otokluog          #+#    #+#             */
/*   Updated: 2022/07/05 15:02:06 by otokluog         ###   ########.fr       */
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

static int	valid_map(t_vars *game)
{
	int	i;
	int	y;

	i = 0;
	while (game->map[i] != NULL)
	{
		y = 0;
		while (game->map[i][y] != '\0')
		{
			if (game->map[i][y] == '1' || game->map[i][y] == 'P'
				|| game->map[i][y] == '0' || game->map[i][y] == 'C'
				|| game->map[i][y] == 'E')
				y++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_vars	game;

	if (ac == 2)
	{
		game.map = mapread(av[1]);
		if (map_check(&game) && av_check(av[1]) && valid_map(&game))
		{
			init(&game);
			so_play(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			ft_printf("Error\n");
			if (av_check(av[1]) == 0)
				ft_printf("Hatalı harita uzantısı.");
			else
				ft_printf("Hatalı harita.");
			if (game.map)
				free(game.map);
		}
	}
	if (ac < 2 || ac > 2)
		ft_printf("Hatalı parametre.");
	return (0);
}
