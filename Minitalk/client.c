/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:38:40 by tuaktas           #+#    #+#             */
/*   Updated: 2022/06/27 13:19:03 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"

void	bit(int sig, char a)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((a >> i) & 1)
			kill (sig, SIGUSR1);
		else
			kill (sig, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			bit(ft_atoi(av[1]), av[2][i]);
			i++;
		}
	}
}
