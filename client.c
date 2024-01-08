/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:15:01 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/08 09:43:13 by stigkas          ###   ########.fr       */
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
		--i;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_char(server_pid, argv[2][i]);
			++i;
		}
	}
	else
		exit(1);
	return (0);
}
