/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:28:06 by ametta            #+#    #+#             */
/*   Updated: 2021/06/18 11:37:59 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

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

	i = 32;
	c = 0;
	while (i >= 0)
	{
		if (bin[i] == 1)
			c += power_of_two(i);
		i--;
	}
	return ((char)c);
}

static void	decode(int sig)
{
	static int				bin[8];
	static int				i = 0;
	static int				j = 0;
	static unsigned char	*str = NULL;
	static int				client_pid = 0;

	if (!str)
		str = (unsigned char *)malloc(sizeof(unsigned char) * TEXT_SIZE);
	if (sig == SIGUSR1)
		bin[i++] = 1;
	else if (sig == SIGUSR2)
		bin[i++] = 0;
	if (i > 7)
	{
		if (j == TEXT_SIZE)
			str = ft_realloc(str, TEXT_SIZE);
		str[j++] = convert_bin_to_dec(bin);
		if (str[j - 1] == 0 && !client_pid)
		{
			client_pid = ft_atoi((char *)str);
			free(str);
			str = NULL;
			j = 0;
		}
		else if (str[j - 1] == 0)
		{
			ft_putendl((char *)str);
			free(str);
			str = NULL;
			j = 0;
			kill(client_pid, SIGUSR1);
			client_pid = 0;
		}
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("Welcome into Minitalk - BONUS\n");
	ft_putstr("To start the chat, share this code to the client: ");
	ft_putnbr(pid);
	ft_putstr("\nThe chat will begin from here. Have fun!\n");
	ft_putstr("------------------------------------------\n");
	while (1)
	{
		signal(SIGUSR1, decode);
		signal(SIGUSR2, decode);
		pause();
	}
	return (0);
}
