/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 08:47:28 by ametta            #+#    #+#             */
/*   Updated: 2021/06/18 08:48:41 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned char	*ft_realloc(unsigned char *str, int to_add)
{
	unsigned char	*new;
	int				len;

	len = 0;
	if (str)
		while (str[len])
			len++;
	new = (unsigned char *)malloc(sizeof(unsigned char) * (len + to_add));
	if (new)
	{
		len = 0;
		if (str)
		{
			while (str[len])
			{
				new[len] = str[len];
				len++;
			}
		}
		while (len < to_add)
			new[len] = '\0';
	}
	free(str);
	return (new);
}

void	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		ft_putchar(s[i++]);
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

void	ft_putendl(const char *s)
{
	if (s)
	{
		ft_putstr(s);
		ft_putchar('\n');
	}
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}
