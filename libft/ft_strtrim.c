/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:54:27 by otokluog          #+#    #+#             */
/*   Updated: 2022/02/09 17:08:51 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[j] && ft_strchr(set, s1[j]))
			j++;
	i = ft_strlen(&s1[j]);
	while (i && ft_strchr(set, s1[i + j]))
		i--;
	str = ft_substr(&s1[j], 0, i + 1);
	return (str);
}
