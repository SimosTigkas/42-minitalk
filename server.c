/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:15:05 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/19 16:13:16 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Receives a message from the client!!
#include "includes/minitalk.h"

void	ft_get_the_len(int sig, size_t *m_len)
{
	static size_t	len = 0;
	static size_t	multiplier = 1;

	len += multiplier * (sig - 30);
	multiplier *= 2;
	if (multiplier > INT_MAX)
	{
		*m_len = len;
		len = 0;
		multiplier = 1;
	}
}

int	ft_get_message(char *msg, int sig, int m_len)
{
	static int	c = 0;
	static int	i = 0;
	static int	multiplier = 1;

	c += multiplier * (sig - 30);
	multiplier *= 2;
	if (multiplier == 256)
	{
		msg[i] = c;
		i++;
		c = 0;
		multiplier = 1;
	}
	if (i == m_len)
	{
		i = 0;
		m_len = 0;
		return (1);
	}
	else
		return (0);
}

void	ft_get_string(int sig, siginfo_t *info, void *context)
{
	static char		*msg;
	static size_t	msg_len;

	(void)context;
	(void)info;
	if (msg_len)
	{
		if (msg == NULL)
		{
			msg = malloc(msg_len + 1);
			if (msg == NULL)
				exit(1);
		}
		if (ft_get_message(msg, sig, msg_len))
		{
			write(1, msg, msg_len);
			write(1, "\n", 1);
			free(msg);
			msg = NULL;
			msg_len = 0;
		}
	}
	else
		ft_get_the_len(sig, &msg_len);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_get_string;
	ft_printf("Server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
