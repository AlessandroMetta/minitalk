/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:32:50 by ametta            #+#    #+#             */
/*   Updated: 2021/06/11 12:57:40 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define TEXT_SIZE 1024

# include <signal.h>
# include "../libft/libft.h"

unsigned char *ft_realloc(unsigned char *str, int to_add);

#endif