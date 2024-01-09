/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:15:05 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/09 13:16:02 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	handle_signal(int bit)
{
	static int				bit_index;
	static unsigned char	current_char;

	current_char |= (bit << bit_index);
	if (bit)
		current_char = current_char | bit;
	++bit_index;
	if (bit_index == 8)
	{
		ft_printf("The current character is: %c\n", current_char);
		bit_index = 0;
		current_char = 0;
	}
}

void	sigusr1_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Received SIGUSR1\n");
		handle_signal(1);
	}
}

void	sigusr2_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("Received SIGUSR2\n");
		handle_signal(0);
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sigusr1_handler);
		signal(SIGUSR2, sigusr2_handler);
		pause();
	}
	return (0);
}
