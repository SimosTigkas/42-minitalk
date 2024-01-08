/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:32:04 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/08 12:31:24 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "libft.h"
# include <string.h>
# include <fcntl.h>
// # define MAX_STRING_LENGTH 2147483647

// signal struct s_sa
// {
// 	struct sa	*sa_sigaction;
// }	sa;

void	sigusr1_handler(int sig);
void	sigusr2_handler(int sig);
void	handle_signal(int bit);

#endif
