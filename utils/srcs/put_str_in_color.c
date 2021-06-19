/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_in_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:51:53 by ametta            #+#    #+#             */
/*   Updated: 2021/06/19 16:34:09 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	put_str_in_color(char *color, char *str)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(TEXT_COLOR_DEFAULT);
}
