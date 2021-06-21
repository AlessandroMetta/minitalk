/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:15:14 by ametta            #+#    #+#             */
/*   Updated: 2021/06/21 12:29:40 by ametta           ###   ########.fr       */
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

static unsigned char	convert_signal_to_unchr(int *signal_collector)
{
	int			i;
	int			c;

	i = 8;
	c = 0;
	while (i >= 0)
	{
		if (signal_collector[i] == 1)
			c += power_of_two(i);
		i--;
	}
	return ((unsigned char)c);
}

static void	additional(int *j, unsigned char **str, int *realloc_counter)
{
	static int	client_pid = 0;

	if ((*str)[*j] == 0 && !client_pid)
	{
		client_pid = ft_atoi((char *)(*str));
		free(*str);
		*str = NULL;
		*j = -1;
	}
	if ((*str)[*j] == 0)
	{
		ft_putendl((char *)*str);
		free(*str);
		*str = NULL;
		*j = -1;
		*realloc_counter = 16;
	}
}

static void	decode(int sig)
{
	static int				signal_collector[8];
	static int				i = 0;
	static int				j = 0;
	static unsigned char	*str = NULL;
	static int				realloc_counter = 16;

	if (!str)
		str = malloc(sizeof(unsigned char) * realloc_counter);
	if (sig == SIGUSR1)
		signal_collector[i++] = 1;
	else if (sig == SIGUSR2)
		signal_collector[i++] = 0;
	if (i > 7)
	{
		if (j == (realloc_counter - 1))
		{
			str[j] = 0;
			str = (unsigned char *)ft_realloc((char *)str, STR_MAX_LEN);
			realloc_counter += STR_MAX_LEN;
		}
		str[j] = convert_signal_to_unchr(signal_collector);
		additional(&j, &str, &realloc_counter);
		i = 0;
		j++;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	put_menu_server(pid);
	while (1)
	{
		signal(SIGUSR1, decode);
		signal(SIGUSR2, decode);
		pause();
	}
	return (0);
}
