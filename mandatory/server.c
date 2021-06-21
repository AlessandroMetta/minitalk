/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:15:14 by ametta            #+#    #+#             */
/*   Updated: 2021/06/21 09:14:22 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

static char	convert_bin_to_char(int *signal_collector)
{
	int			i;
	int		c;

	i = 8;
	c = 0;
	while (i >= 0)
	{
		if (signal_collector[i] == 1)
			c += power_of_two(i);
		i--;
	}
	return ((char)c);
}

static void	additional(int *j, char **str)
{
	if ((*str)[*j - 1] == 0)
	{
		ft_putendl(*str);
		free(*str);
		*str = NULL;
		*j = 0;
	}
}

static void	decode(int sig)
{
	static int				signal_collector[8];
	static int				i = 0;
	static int				j = 0;
	static char				*str = NULL;
	static int				realloc_counter = 16;

	if (!str)
		str = (char *)malloc(sizeof(char) * realloc_counter);
	if (sig == SIGUSR1)
		signal_collector[i++] = 1;
	else if (sig == SIGUSR2)
		signal_collector[i++] = 0;
	if (i > 7)
	{
		if (j == realloc_counter)
		{
			str = ft_realloc(str, realloc_counter);
			realloc_counter *= realloc_counter;
		}
		str[j++] = convert_bin_to_char(signal_collector);
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
