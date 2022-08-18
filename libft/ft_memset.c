/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <omer.faruk.tokluoglu@hotmai      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:49:20 by otokluog          #+#    #+#             */
/*   Updated: 2022/02/08 15:14:36 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *src, int c, size_t len)
{
	unsigned char	*dec;

	dec = src;
	while (len--)
		*dec++ = (unsigned char)c;
	return (src);
}
