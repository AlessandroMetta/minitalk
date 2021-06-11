/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:37:08 by ametta            #+#    #+#             */
/*   Updated: 2021/06/11 15:18:50 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	char_to_bin(unsigned char chr, int server_pid)
{
	int	i;

	i = 0;
	while (i < 32)
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

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	i = -1;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
			ft_putstr("INVALID PID\n");
			return (1);
		}
		while (argv[2][++i])
			char_to_bin(argv[2][i], server_pid);
		char_to_bin(0, server_pid);
		return (0);
	}
	ft_putstr("WRONG ARGUMENT\n");
	ft_putstr("Usage: ./client [server pid] \"text to send\"\n");
	return (1);
}
