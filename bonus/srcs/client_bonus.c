/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:37:08 by ametta            #+#    #+#             */
/*   Updated: 2021/06/18 18:08:40 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

static void	char_to_bin(unsigned char chr, int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (chr % 2 == 1)
			kill(server_pid, SIGUSR1);
		else if (chr % 2 == 0)
			kill(server_pid, SIGUSR2);
		chr /= 2;
		usleep(50);
		i++;
	}
}

void	message(int null)
{
	(void)null;
	ft_putstr("message delivered and printed\n");
	exit(EXIT_SUCCESS);
}

void	send_str(char *str, int server_pid)
{
	int	i;

	i = -1;
	while (str[++i])
		char_to_bin(str[i], server_pid);
	char_to_bin(0, server_pid);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	signal(SIGUSR1, message);
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
			ft_putstr("INVALID PID\n");
			return (1);
		}
		send_str(ft_itoa(getpid()), server_pid);
		send_str(argv[2], server_pid);
		pause();
	}
	ft_putstr("WRONG ARGUMENT\n");
	ft_putstr("Usage: ./client [server pid] \"text to send\"\n");
	return (EXIT_FAILURE);
}
