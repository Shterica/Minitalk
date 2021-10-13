/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shterica <shterica@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:09:27 by shterica          #+#    #+#             */
/*   Updated: 2021/10/12 21:08:54 by shterica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("Sever PID: ", 1);
	ft_putnbr(pid);
	write(1, "\n", 1);
}

int	main(void)
{
	struct sigaction	sig_s;

	sigemptyset(&sig_s.sa_mask);
	sig_s.sa_sigaction = byte_reciever;
	sig_s.sa_flags = SA_SIGINFO;
	print_pid();
	if (sigaction(SIGUSR1, &sig_s, NULL) || sigaction(SIGUSR2, &sig_s, NULL))
	{
		ft_putstr_fd("Server: error in sigaction\n", 2);
		return (-1);
	}
	while (1)
		pause();
	return (0);
}

void	byte_reciever(int signal, siginfo_t *info, void *data)
{
	static int	bit;
	static char	c;

	(void)data;
	if (signal == SIGUSR1)
		c = c | (0 << bit);
	else if (signal == SIGUSR2)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		print_byte(c, info);
		c = 0;
		bit = 0;
	}
	if (kill(info->si_pid, SIGUSR1))
		ft_putstr_fd("Server: client not responding\n", 2);
}

void	print_byte(char c, siginfo_t *info)
{
	if (c == '\0')
	{
		write(1, "\n", 1);
		if (kill(info->si_pid, SIGUSR2))
			ft_putstr_fd("Server: client not responding\n", 2);
	}
	else
		write(1, &c, 1);
}
