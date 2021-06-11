/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:37:53 by ametta            #+#    #+#             */
/*   Updated: 2021/06/11 15:38:05 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

void			ft_putstr(const char *s);
void			ft_putnbr(const int n);
void			ft_putchar(const char c);
int				ft_atoi(const char *str);
int				ft_isspace(const char c);
int				ft_isdigit(const int c);
void			ft_putendl(const char *s);
unsigned char	*ft_realloc(unsigned char *str, int to_add);

#endif