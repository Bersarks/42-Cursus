/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:35:39 by otokluog          #+#    #+#             */
/*   Updated: 2022/02/18 16:35:49 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_dst;

	ptr_dst = (unsigned char *)s;
	while (n--)
	{		
		if (*ptr_dst == (unsigned char)c)
			return (ptr_dst);
		ptr_dst++;
	}
	return (NULL);
}
