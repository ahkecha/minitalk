/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:08:03 by ahkecha           #+#    #+#             */
/*   Updated: 2021/12/20 11:45:07 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	unshift_that_char(int num)
{
	static int i;
    static char byte;

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
	int	pid;

	(void)av;
	pid = getpid();
	if(ac == 1)
	{
		ft_putstr("PID: ");
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
		signal(SIGUSR1, unshift_that_char);
		signal(SIGUSR2, unshift_that_char);
		while(1)
			pause();
	}
	exit(EXIT_SUCCESS);
}
