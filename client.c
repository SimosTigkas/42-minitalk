/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:15:01 by stigkas           #+#    #+#             */
/*   Updated: 2023/12/18 13:53:26 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*str_send;
	int		i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		str_send = argv[2];
		kill(server_pid, SIGUSR1);
		sleep(1);
		while (str_send[i] != '\0')
		{
			if (str_send[i] == '1')
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(50000);
		}
	}
	return (0);
}
