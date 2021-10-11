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

	sigemptyset(&sig_clnt.sa_mask);
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
		if (!send_string(pid, av[2]))
		{
			ft_putstr_fd("Client: error in transfer\n", 2);
			return (-1);
		}
	}
	else
		write(1, "Wrong args. Enter 2 args: server PID and a message", 51);
	return (0);
}

int	send_string(pid_t pid, char *str)
{
	
}