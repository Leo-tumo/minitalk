/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:40:43 by letumany          #+#    #+#             */
/*   Updated: 2022/02/09 10:25:48 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	char_sender(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		usleep(100);
		if (c & (64 >> i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
	}
}

void	is_num(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] < '0' || c[i] > '9')
			exit (1);
		i++;
	}
}

void	arg_analyzer(char *c, int pid)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '0')
			char_sender(0, pid);
		else
			char_sender(c[i], pid);
		i++;
	}
	char_sender('\n', pid);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		exit (1);
	is_num(argv[1]);
	pid = (pid_t)atoi(argv[1]);
	if (pid == 0)
		exit (1);
	arg_analyzer(argv[2], pid);
	return (0);
}
