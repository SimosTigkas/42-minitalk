/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:15:01 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/15 12:24:02 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	ft_send_str_len(int server_pid, char *str)
{
	int		i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(str);
	if (str_len > MAX_LEN)
	{
		ft_printf("The message is too long");
		return (0);
	}
	while (i < 32)
	{
		kill(server_pid, SIGUSR1 + (1 & (str_len >> i)));
		usleep(50);
		i++;
	}
	return (1);
}

void	ft_send_str(int server_pid, char	*str)
{
	int	i;
	int	c;

	while (*str)
	{
		c = *str;
		i = 0;
		while (i < 8)
		{
			kill(server_pid, SIGUSR1 + (1 & (c >> i)));
			usleep(50);
			i++;
		}
		str++;
	}
}

int	main(int argc, char **av)
{
	int		server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(av[1]);
		if (server_pid <= 0)
		{
			ft_putstr_fd("Invalid PID: ", 2);
			ft_putstr_fd(av[1], 2);
			exit(1);
		}
		if (!ft_send_str_len(server_pid, av[2]))
			exit(0);
		ft_send_str(server_pid, av[2]);
	}
	else
	{
		ft_printf("To talk with the client: ./client [PID] [string]\n");
		exit(1);
	}
	return (0);
}
