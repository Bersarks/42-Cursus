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
	char	*dup;

	dup = (char *)malloc(ft_strlen(s1) + 1);
	if (dup == NULL)
		return (NULL);
	ft_memcpy (dup, s1, (ft_strlen(s1) + 1));
	return (dup);
}
