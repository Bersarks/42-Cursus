/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:17:27 by otokluog          #+#    #+#             */
/*   Updated: 2022/02/12 20:57:55 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*x;

	if (!s || !f)
		return (NULL);
	i = 0;
	x = malloc((ft_strlen(s) + 1) * (sizeof(char)));
	if (!x)
		return (NULL);
	while (s[i])
	{
		x[i] = s[i];
		i++;
	}
	x [i] = '\0';
	i = 0;
	while (x[i])
	{
		x[i] = f(i, x[i]);
		i++;
	}
	return (x);
}
