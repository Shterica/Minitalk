/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shterica <shterica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:09:07 by shterica          #+#    #+#             */
/*   Updated: 2021/10/11 19:11:04 by shterica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

/*
** utilities
*/
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);
int		ft_strlen(char *s);
void	ft_putchar_fd(char c, int fd);

/*
** server functions
*/

void	ft_putnbr(int nb);
void	print_pid(void);
void	byte_reciever(int signal, siginfo_t *info, void *data);
void	print_byte(char c, siginfo_t *info);

/*
** client functions
*/

int		send_string(int pid, char *str);
int		send_char(pid_t pid, char c);
void	serv_response(int signal, siginfo_t *info, void *data);

#endif