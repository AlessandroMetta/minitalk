/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:14:56 by ametta            #+#    #+#             */
/*   Updated: 2021/06/21 15:44:20 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	char_to_bin(char chr, int server_pid)
{
	int	i;

	i = 0;
	if (chr < 0)
		return ;
	while (i < 8)
	{
		if (chr % 2 == 1)
			kill(server_pid, SIGUSR1);
		else if (chr % 2 == 0)
			kill(server_pid, SIGUSR2);
		chr /= 2;
		usleep(100);
		i++;
	}
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

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
			put_str_in_color(TEXT_COLOR_RED, "ERROR: invalid PID\n");
			return (EXIT_FAILURE);
		}
		send_str(argv[2], server_pid);
		return (EXIT_SUCCESS);
	}
	put_str_in_color(TEXT_COLOR_RED, "WRONG ARGUMENT\n");
	put_str_in_color(TEXT_COLOR_RED, "Usage: ./client [server pid] ");
	put_str_in_color(TEXT_COLOR_RED, "\"text to send\"\n");
	return (EXIT_FAILURE);
}
