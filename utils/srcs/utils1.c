/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:15:03 by ametta            #+#    #+#             */
/*   Updated: 2021/06/19 18:14:33 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

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
