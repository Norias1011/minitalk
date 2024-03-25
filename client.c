/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:28:29 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/25 15:37:46 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(420);
	}
}

void	read_receipt(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Bit 1 received\n");
	else if (signal == SIGUSR2)
		ft_printf("Bit 0 received\n");
}
int	main(int argc, char *argv[])
{
	__pid_t server_pid;
	const char *message;
	int i;

	signal(SIGUSR1, read_receipt);
	signal(SIGUSR2, read_receipt);
	if (argc != 3)
	{
		ft_printf("Wrong arguments number : (PID) (Message)");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
		send_signal(server_pid, message[i++]);
	send_signal(server_pid, '\0');
	return (0);
}