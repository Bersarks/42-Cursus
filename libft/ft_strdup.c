/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <omer.faruk.tokluoglu@hotmai      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:23:32 by otokluog          #+#    #+#             */
/*   Updated: 2022/02/08 20:11:08 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	char	*b;
	int		i;

	i = 0;
	b = (char *)s1;
	a = malloc (sizeof(*a) * ft_strlen(b) + 1);
	if (a == NULL)
		return (NULL);
	while (b[i] != '\0')
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
