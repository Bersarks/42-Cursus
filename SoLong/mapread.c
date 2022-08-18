/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:34:02 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/07 10:37:05 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**mapread(char *file)
{
	int		fd;
	char	**map;
	char	*gnl;
	char	*read;
	char	*whole;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	whole = ft_strdup("");
	while (fd > 0)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		read = whole;
		whole = ft_strjoin(read, gnl);
		free(gnl);
		free(read);
	}
	map = ft_split(whole, '\n');
	free (whole);
	close (fd);
	return (map);
}
