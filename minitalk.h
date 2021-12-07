/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:06:15 by ahkecha           #+#    #+#             */
/*   Updated: 2021/12/07 12:12:47 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>

void	ft_putchar(char c, int fd);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);

#endif
