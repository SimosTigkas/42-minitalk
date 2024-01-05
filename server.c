/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:15:05 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/05 16:26:24 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include <stdio.h>

void	sigusr1_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_strcpy(g_sstr, g_cstr);
		printf("Received SIGUSR1\n");
		printf("Received string: %s\n", g_sstr);
	}
}

void	sigusr2_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_strcpy(g_sstr, g_cstr);
		printf("Received the SIGUSR2 signal!!\n");
		printf("Received string: %s\n", g_sstr);
	}
}

int	main(void)
{
	int		c;
	pid_t	server_pid;
	// pid_t	client_pid;

	server_pid = getpid();
	c = 0;
	ft_memset(g_sstr, 0, sizeof(g_sstr));
	printf("Server PID: %d\n", server_pid);
	signal(SIGUSR1, sigusr1_handler);
	// signal(SIGUSR2, sigusr2_handler);
	kill(server_pid, SIGUSR1);
	if (kill(server_pid, SIGUSR1) == -1)
		exit(1);
	sleep(1);
	// kill(client_pid, SIGUSR1);
	// if (kill(client_pid, SIGUSR1) == -1)
	// 	exit(1);
	while (c < 1)
	{
		pause();
		c++;
	}
	return (0);
}
