/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:06:15 by ahkecha           #+#    #+#             */
/*   Updated: 2021/12/23 17:21:36 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define CHAR_BIT 8
# define SNDING_MSG "Sending message ⌛️"
# define SENT_SUCCESS "Message successefuly sent ✅!"
# define PID_ERR "Invalid PID\nUsage: ./client [PID] ...\n"
# define ERR_ARG "Invalid arguments\nUsage: ./client [PID] [MSG]\n"
# define SRV_PIDERR "Server PID is invalid or server is not running ❌"
# define NO_MSG "Please input a message to send\nUsage: ./client [PID] [MSG]"

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putchar(char c, int fd);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl(char *str);
void	ft_putchar_fd(char c, int fd);
void	_send(char *message, int pid);
void	shift_that_char(char byte, int pid);

#endif
