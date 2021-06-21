/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:14:56 by ametta            #+#    #+#             */
/*   Updated: 2021/06/21 16:00:44 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	unchar_to_bin(unsigned char chr, int server_pid)
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
		usleep(100);
		i++;
	}
}

void	message(int null)
{
	(void)null;
	put_str_in_color(TEXT_COLOR_GREEN, "message delivered and printed\n");
	exit(EXIT_SUCCESS);
}

void	send_str(char *str, int server_pid)
{
	int	i;

	i = -1;
	while (str[++i])
		unchar_to_bin(str[i], server_pid);
	unchar_to_bin(0, server_pid);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*str;

	signal(SIGUSR1, message);
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
			put_str_in_color(TEXT_COLOR_RED, "ERROR: invalid PID\n");
			return (EXIT_FAILURE);
		}
		str = ft_itoa(getpid());
		send_str(str, server_pid);
		free(str);
		send_str(argv[2], server_pid);
		sleep(1);
		put_str_in_color(TEXT_COLOR_RED, "ERROR: something goes wrong\n");
		return (EXIT_FAILURE);
	}
	put_str_in_color(TEXT_COLOR_RED, "WRONG ARGUMENT\n");
	put_str_in_color(TEXT_COLOR_RED, "Usage: ./client [server pid] ");
	put_str_in_color(TEXT_COLOR_RED, "\"text to send\"\n");
	return (EXIT_FAILURE);
}
