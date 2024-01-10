/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:15:01 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/10 15:33:40 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	send_char(int server_pid, char character)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = (0x01 << i) & character;
		if (bit != 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **av)
{
	int		server_pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(av[1]);
		if (server_pid <= 0)
		{
			ft_putstr_fd("Invalid PID: ", 2);
			ft_putstr_fd(av[1], 2);
			exit(1);
		}
		while (av[2][i])
			send_char(server_pid, av[2][i++]);
		send_char(server_pid, '\0');
	}
	else
	{
		ft_printf("To talk with the client: ./client [PID] [string]\n");
		exit(1);
	}
	return (0);
}
