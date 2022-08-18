/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:40:36 by tuaktas           #+#    #+#             */
/*   Updated: 2022/06/27 13:24:13 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"

void	handler(int signal, siginfo_t *info, void *x)
{
	static char		a;
	static int		i = 7;

	if (signal == SIGUSR1)
		a = a | (1 << i);
	else
		a = a | (0 << i);
	i--;
	if (i < 0)
	{
		ft_printf ("%c", a);
		kill(info->si_pid, SIGUSR2);
		i = 7;
		x = 0;
		a = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	ft_printf("PID = %d \n", getpid());
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
