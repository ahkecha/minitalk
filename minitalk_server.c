/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:08:03 by ahkecha           #+#    #+#             */
/*   Updated: 2021/12/27 15:42:25 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	reset(int *curr_pid, int *cli_pid, int *i, char *byte)
{
	*cli_pid = *curr_pid;
	*byte = 0;
	*i = 0;
}

void	unshift_that_char(int num, siginfo_t *inf, void *p)
{
	static int	i;
	static char	byte;
	static int	curr_pid;
	static int	cli_pid;

	(void)p;
	if (!cli_pid)
		cli_pid = inf->si_pid;
	curr_pid = inf->si_pid;
	if (curr_pid != cli_pid)
		reset(&curr_pid, &cli_pid, &i, &byte);
	if (num == SIGUSR2)
	{
		(byte |= (0x80 >> i));
		i++;
	}
	else
		i++;
	if (i == 8)
	{
		write(1, &byte, 1);
		i = 0;
		byte = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	ret;

	(void)av;
	pid = getpid();
	ret.sa_sigaction = unshift_that_char;
	ret.sa_flags = SA_SIGINFO;
	if (ac == 1)
	{
		ft_putstr("PID: ");
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
		while (1)
		{
			sigaction(SIGUSR1, &ret, 0);
			sigaction(SIGUSR2, &ret, 0);
			pause();
		}
	}
	exit(EXIT_FAILURE);
}
