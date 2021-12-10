/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:13:48 by ahkecha           #+#    #+#             */
/*   Updated: 2021/12/07 18:07:06 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int	pid;

	if(ac > 1 && ac <= 3 )
	{
		pid = ft_atoi(av[1]);
		if (pid == 0 || pid < 0)
		{
			ft_putstr(PID_ERR);
			exit (EXIT_FAILURE);
		}
		else
		{
			ft_putendl(SNDING_MSG);
			_send(av[2], pid);
			usleep(100);
			ft_putendl(SENT_SUCCESS);
			exit(EXIT_SUCCESS);
		}
	}
	ft_putstr(ERR_ARG);
}
