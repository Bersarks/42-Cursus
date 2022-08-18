/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:12:06 by otokluog          #+#    #+#             */
/*   Updated: 2022/07/05 15:12:07 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	buffer;
	char	*line;
	int		reader;
	int		i;

	reader = 1;
	i = 0;
	line = (char *)malloc(sizeof(char) * 1024);
	buffer = 0;
	while (reader > 0)
	{
		reader = read(fd, &buffer, 1);
		if (reader <= 0)
			break ;
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
	}
	line[i] = '\0';
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
