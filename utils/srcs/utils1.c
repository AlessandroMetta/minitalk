/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:15:03 by ametta            #+#    #+#             */
/*   Updated: 2021/06/21 15:55:08 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	put_str_in_color(char *color, char *str)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(TEXT_COLOR_DEFAULT);
}

char	*ft_realloc(char *str, int to_add)
{
	char	*new;
	int		len;

	len = -1;
	if (str)
	{
		while (str[++len])
			;
	}
	new = malloc(sizeof(char) * (len + to_add));
	if (new)
	{
		len = -1;
		if (str)
		{
			while (str[++len])
				new[len] = str[len];
		}
		new[len] = 0;
	}
	free(str);
	str = NULL;
	return (new);
}

void	ft_putnbr(const int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr((n) * (-1));
	}
	else if (n < 10)
	{
		ft_putchar(n + 48);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(((n % 10) + 48));
	}
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	size_t	num;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((num > 2147483648 && sign == -1) || (num > 2147483647 && sign == 1))
	{
		put_str_in_color(TEXT_COLOR_RED, "ERROR: OVER INTEGER RANGE\n");
		exit(1);
	}
	return (num * sign);
}

void	put_menu_server(pid_t	pid)
{
	char	*str_pid;

	str_pid = ft_itoa(pid);
	put_str_in_color(TEXT_COLOR_GREEN, "\t\t\tWelcome in Minitalk\n");
	put_str_in_color(TEXT_COLOR_GREEN, "To start the chat,");
	put_str_in_color(TEXT_COLOR_GREEN, "share this code to the client: ");
	put_str_in_color(TEXT_COLOR_GREEN, str_pid);
	put_str_in_color(TEXT_COLOR_GREEN, "\nThe chat will begin from here. ");
	put_str_in_color(TEXT_COLOR_GREEN, "Have fun!\n");
	put_str_in_color(TEXT_COLOR_GREEN, "=================================");
	put_str_in_color(TEXT_COLOR_GREEN, "=================================\n");
	free(str_pid);
}
