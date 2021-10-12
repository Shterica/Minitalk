/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shterica <shterica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:08:47 by shterica          #+#    #+#             */
/*   Updated: 2021/10/11 19:30:12 by shterica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	struct sigaction	sig_c;
	int					pid;

	sigemptyset(&sig_c.sa_mask);
	sig_c.sa_sigaction = serv_response;
	sig_c.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig_c, NULL) || sigaction(SIGUSR2, &sig_c, NULL))
	{
		ft_putstr_fd("Client: error in sigaction\n", 2);
		return (-1);
	}
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (send_string(pid, av[2]))
		{
			ft_putstr_fd("Client: error in transfer\n", 2);
			return (-1);
		}
	}
	else
		ft_putstr_fd("Wrong args. Enter 2 args: server PID and a message\n", 2);
	return (0);
}

int	send_string(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (send_char(pid, str[i]))
			return (-1);
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

int	send_char(pid_t pid, char c)
{
	int bit;
	int	error;

	error = 0;
	bit = 0;
	while(bit < 8)
	{
		if ((c >> bit) & 1)
			error = kill(pid, SIGUSR2);
		else
			error = kill(pid, SIGUSR1);
		if (error)
			return (error);
		bit++;
		if (!usleep(1000))
			return (-1);
	}
	return (error);
}

void	serv_response(int signal, siginfo_t *info, void *data)
{
	(void)info;
	(void)data;

	if (signal == SIGUSR2)
		ft_putstr_fd("bogus binted\n", 1);
}