/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:28:44 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/24 18:08:33 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static int	pid;
	static int	i;
	static char	str;
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	ft_bzero(&action, sizeof(act));
	ft_printf("Welcome in Akinzeli Minitalk\n");
	ft_printf("Server PID : %d\n", getpid());
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
	{
		ft_printf("Error sigaction\n");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &action, NULL) == -1)
	{
		ft_printf("Error sigaction\n");
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
}
