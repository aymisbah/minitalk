/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:09:26 by aymisbah          #+#    #+#             */
/*   Updated: 2025/02/25 17:21:27 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <stdarg.h>

typedef struct s_signal_state
{
	int		i;
	char	c;
	pid_t	pid;
}	t_signal_state;

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		isnmb(char c);
int		ft_putnbr(int n);
int		ft_putchar(int c);
int		ft_printf(const char *format, ...);

void	send_bit(int pid, int bit);
void	check_sig(int sig);
void	send_msg(int pid, const char *msg);

#endif