/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <omer.faruk.tokluoglu@hotmai      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:09:29 by otokluog          #+#    #+#             */
/*   Updated: 2022/02/08 10:56:15 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dp;
	const unsigned char		*sp;

	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		dp = dst + len;
		sp = src + len;
		while (len-- > 0)
		{
			*--dp = *--sp;
		}
	}
	else
	{
		dp = dst;
		sp = src;
		while (len-- > 0)
		{
			*dp++ = *sp++;
		}
	}
	return (dst);
}
