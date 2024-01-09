/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:15:01 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/09 13:08:07 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	send_bit(int server_pid, int bit)
{
	if (bit == 1)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
	usleep(42);
}

void	send_char(int server_pid, char character)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (character >> i) & 1;
		send_bit(server_pid, bit);
		i--;
	}
}

void	send_string(int pid, const char *str)
{
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\0');
}


int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
		{
			ft_putstr_fd("Invalid PID: ", 2);
			ft_putstr_fd(argv[1], 2);
			exit(1);
		}
		send_string(server_pid, argv[2]);
	}
	else
	{
		ft_putstr_fd("Usage: ./client [PID] [string]\n", 2);
		exit(1);
	}
	return (0);
}
