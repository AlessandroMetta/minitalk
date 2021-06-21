/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:15:14 by ametta            #+#    #+#             */
/*   Updated: 2021/06/21 09:34:24 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	power_of_two(int pow)
{
	int			res;

	res = 1;
	while (pow > 0)
	{
		res = res * 2;
		pow--;
	}
	return (res);
}

static unsigned char	convert_bin_to_dec(int *bin)
{
	int			i;
	int			c;

	i = 8;
	c = 0;
	while (i >= 0)
	{
		if (bin[i] == 1)
			c += power_of_two(i);
		i--;
	}
	return ((unsigned char)c);
}

static void	additional(int *j, unsigned char **str)
{
	static int	client_pid = 0;

	if ((*str)[*j - 1] == 0 && !client_pid)
	{
		client_pid = ft_atoi((char *)(*str));
		free(*str);
		*str = NULL;
		*j = 0;
	}
	else if ((*str)[*j - 1] == 0)
	{
		ft_putendl((char *)*str);
		free(*str);
		*str = NULL;
		*j = 0;
		kill(client_pid, SIGUSR1);
		client_pid = 0;
	}
}

static void	decode(int sig)
{
	static int				bin[8];
	static int				i = 0;
	static int				j = 0;
	static unsigned char	*str = NULL;
	static int				realloc_counter = 16;

	if (!str)
		str = (unsigned char *)malloc(sizeof(unsigned char) * realloc_counter);
	if (sig == SIGUSR1)
		bin[i++] = 1;
	else if (sig == SIGUSR2)
		bin[i++] = 0;
	if (i > 7)
	{
		if (j == realloc_counter)
		{
			str = (unsigned char *)ft_realloc((char *)str, realloc_counter);
			realloc_counter *= realloc_counter;
		}
		str[j++] = convert_bin_to_dec(bin);
		additional(&j, &str);
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	put_str_in_color(TEXT_COLOR_GREEN, "\t\t\tWelcome in Minitalk\n");
	put_str_in_color(TEXT_COLOR_GREEN, "To start the chat,");
	put_str_in_color(TEXT_COLOR_GREEN, "share this code to the client: ");
	put_str_in_color(TEXT_COLOR_GREEN, ft_itoa(pid));
	put_str_in_color(TEXT_COLOR_GREEN, "\nThe chat will begin from here. ");
	put_str_in_color(TEXT_COLOR_GREEN, "Have fun!\n");
	put_str_in_color(TEXT_COLOR_GREEN, "=================================");
	put_str_in_color(TEXT_COLOR_GREEN, "=================================\n");
	while (1)
	{
		signal(SIGUSR1, decode);
		signal(SIGUSR2, decode);
		pause();
	}
	return (0);
}
