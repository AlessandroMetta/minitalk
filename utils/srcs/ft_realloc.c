/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:48:46 by ametta            #+#    #+#             */
/*   Updated: 2021/06/11 15:36:13 by ametta           ###   ########.fr       */
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
	return (new);
}
