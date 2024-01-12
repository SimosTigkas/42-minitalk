/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:32:04 by stigkas           #+#    #+#             */
/*   Updated: 2024/01/12 16:21:40 by stigkas          ###   ########.fr       */
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
# define MAX_LEN 4294967295
# define INT_MAX 2147483648

void	ft_get_string(int sig, siginfo_t *info, void *context);
int		ft_send_str_len(int server_pid, char *str);
void	ft_send_str(int server_pid, char	*str);
void	ft_get_the_len(int sig, size_t *m_len);
int		ft_get_message(char *msg, int sig, int m_len);

// typedef struct s_vec
// {
// 	char	*buff; //2 * 2 = 4 * 2 = 8 * 
// 	int		size; //8
// 	int		curr_chars; //8
// }				t_vec;

#endif
