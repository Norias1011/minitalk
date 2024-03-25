/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:28:44 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/25 15:59:06 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	str;

	(void)context;
	str |= (signum == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (str == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", str);
		i = 0;
		str = 0;
	}
	else
		str <<= 1;
	if (signum == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signum == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	action;

	ft_bzero(&action, sizeof(action));
	ft_printf("Welcome in Akinzeli Minitalk\n");
	ft_printf("$$\\      $$\\ $$$$$$\\ $$\\   $$\\ $$$$$$\\ $$$$$$$$\\  $$$$$$\\  $$\\       $$\\   $$\\ \n");
	ft_printf("$$$\\    $$$ |\\_$$  _|$$$\\  $$ |\\_$$  _|\\__$$  __|$$  __$$\\ $$ |      $$ | $$  |\n");
	ft_printf("$$$$\\  $$$$ |  $$ |  $$$$\\ $$ |  $$ |     $$ |   $$");
	ft_printf(" /  $$ |$$ |      $$ |$$  / \n");
	ft_printf("$$\\$$\\$$ $$ |  $$ |  $$ $$\\$$ |  $$ |     $$ |   $$$$$$$$ |$$ |      $$$$$");
	ft_printf(" /  \n");
	ft_printf("$$ \\$$$  $$ |  $$ |  $$ \\$$$$ |  $$ |     $$ |   $$  __$$ |$$ |      $$  $$<   \n");
	ft_printf("$$ |\\$ ");
	ft_printf("	/$$ |  $$ |  $$ |\\$$$ |  $$ |     $$ |   $$ |  $$ |$$ |      $$ |\\$$\\  \n");
	ft_printf("$$ | \\_/ $$ |$$$$$$\\ $$ | \\$$ |$$$$$$\\    $$ |   $$ |  $$ |$$$$$$$$\\ $$ | \\$$\\ \n");
	ft_printf("\\__|     \\__|\\______|\\__|  \\__|\\______|   \\__|   \\__|  \\__|\\________|\\__|  \\__|\n");
	ft_printf("Server PID : %d\n", getpid());
	action.sa_sigaction = &signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
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
	return (0);
}
