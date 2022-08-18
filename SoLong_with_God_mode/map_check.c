/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:34:24 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/07 10:36:57 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ret(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i] != NULL)
	{
		if (!(ft_strlen (map[i]) == ft_strlen(map[0])))
			return (0);
		i++;
	}
	return (1);
}

static int	wall_check(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i] != NULL)
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	others(t_vars *game)
{
	int	x;
	int	y;

	game->e_count = 0;
	game->c_count = 0;
	game->p_count = 0;
	x = 0;
	while (game->map[x] != NULL)
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
				game->p_count++;
			else if (game->map[x][y] == 'E')
				game->e_count++;
			else if (game->map[x][y] == 'C')
				game->c_count++;
			y++;
		}
		x++;
	}
	if (game->p_count != 1 || game->e_count == 0 || game->c_count == 0)
		return (0);
	return (1);
}

static int	valid(char **map)
{
	int	i;
	int	y;

	i = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			if (map[i][y] != 'P' && map[i][y] != 'E'
			&& map[i][y] != 'C' && map[i][y] != '1' && map[i][y] != '0')
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	map_check(t_vars *game)
{
	if (ret(game->map) && wall_check(game->map) && others(game)
		&& valid(game->map))
		return (1);
	return (0);
}
