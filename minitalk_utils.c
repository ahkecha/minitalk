/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:08:51 by ahkecha           #+#    #+#             */
/*   Updated: 2021/12/09 14:26:14 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	shift_that_char(char byte, int pid)
{
	int	shift;
    int	res;
    int	bit;

	shift = 0;
	while (shift < 7)
	{
		bit = ((unsigned char )byte << shift) & 1;
		if (bit == 1)
			res = kill(pid, SIGUSR1);
		else
			res = kill(pid, SIGUSR2);
		shift++;
		if (res == -1)
		{
			ft_putendl(SRV_PIDERR);
			exit(EXIT_FAILURE);
		}
		usleep(100);
	}
}


// void	shift_that_char(int byte, int pid)
// {
// 	int res;
// 	int i;
// 	int rem;
// 	int sig;

// 	res = 0;
// 	i = 0;

// 	while(byte > 0)
// 	{
// 		rem = byte % 2;
// 		res = res + (i * rem);
// 		byte = byte / 2;
// 		i = i * 10;
// 	}
// 	if (res == 0)
// 		sig = kill(pid, SIGUSR1);
// 	else if (res == -1)
// 	{
// 		ft_putendl(SRV_PIDERR);
// 		exit(EXIT_FAILURE);
// 	}
// 	else if(res == 1)
// 		sig = kill(pid, SIGUSR2);
// 	usleep(100);
// }

void	_send(char *message, int pid)
{
	int	i;

    i = 0;
    while (message[i] != '\0')
    {
		shift_that_char(message[i], pid);
		i++;
    }
}
void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
}

int		ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
		if (res > 2147483647 && sign == 1)
			return (-1);
		if (res > 2147483648 && sign == -1)
			return (0);
	}
	return (res * sign);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	nb;

	nb = n;
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nb == 2147483648)
		write(fd, "2147483648", 11);
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
		if (nb > 9)
		{
			ft_putnbr_fd((nb / 10), fd);
			ft_putchar_fd((nb % 10 + '0'), fd);
		}
		else
			ft_putchar_fd((nb + '0'), fd);
	}
}

void	ft_putendl(char *str)
{
	ft_putstr(str);
	ft_putchar_fd('\n', 1);
}