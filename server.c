/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:15:05 by stigkas           #+#    #+#             */
/*   Updated: 2023/12/18 13:48:48 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include <stdio.h>

char	g_str[100];

void	sigurs1_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		printf("Received SIGUSR1\n");
		printf("Received string: %s\n", g_str);
	}
}

void	sigurs2_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		printf("Received SIGUSR2\n");
		printf("Received string: %s\n", g_str);
	}
}

int	main(void)
{
	int		c;
	pid_t	server_pid;

	server_pid = getpid();
	c = 0;
	ft_memset(g_str, 0, sizeof(g_str));
	printf("Server PID: %d\n", server_pid);
	signal(SIGUSR1, sigurs1_handler);
	signal(SIGUSR2, sigurs2_handler);
	kill(server_pid, SIGUSR1);
	while (c < 1)
	{
		pause();
		c++;
	}
	return (0);
}
