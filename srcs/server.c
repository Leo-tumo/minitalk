/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:21:26 by letumany          #+#    #+#             */
/*   Updated: 2022/02/09 10:43:25 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_data		g_data;

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
}

void	init_data(void)
{
	g_data.count = 0;
	g_data.bit = 0b00;
}

void	sig_handler(int signum)
{
	g_data.bit |= (signum - 30);
	g_data.count++;
	if (g_data.count == 7)
	{
		write(1, &g_data.bit, 1);
		init_data();
	}
	g_data.bit <<= 1;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;
	char				*c_pid;

	init_data();
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	pid = (int)getpid();
	c_pid = ft_itoa(pid);
	ft_putstr(c_pid);
	free (c_pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
