/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <omer.faruk.tokluoglu@hotmai      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:57:36 by otokluog          #+#    #+#             */
/*   Updated: 2022/02/16 17:40:05 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *hstk, const char *ndl, size_t l)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ndl[j] == '\0')
		return ((char *)hstk);
	while (hstk[i] != '\0')
	{
		j = 0;
		while (hstk[i + j] == ndl[j] && (i + j) < l)
		{
			if (hstk[i + j] == '\0' && ndl[j] == '\0')
				return ((char *)hstk + i);
			j++;
		}
		if (ndl[j] == '\0')
			return ((char *)hstk + i);
		i++;
	}
	return (0);
}
