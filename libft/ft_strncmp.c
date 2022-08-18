/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <omer.faruk.tokluoglu@hotmai      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:42:51 by otokluog          #+#    #+#             */
/*   Updated: 2022/02/08 21:46:12 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while (s1[a] == s2[a] && s1[a] != '\0')
	{
		if (a < n - 1)
			a++;
		else
			return (0);
	}
	return ((unsigned char)(s1[a]) - (unsigned char)(s2[a]));
}
