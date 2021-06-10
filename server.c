/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:28:06 by ametta            #+#    #+#             */
/*   Updated: 2021/06/10 18:53:12 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

int main(void)
{
	pid_t	pid;
	pid = getpid();
	ft_putstr("Welcome into Minitalk\n");
	ft_putstr("To start the chat, share the thi code to the client: ");
	ft_putnbr(pid);
	ft_putstr("\nThe chat will begin from here. Have fun!\n");
	ft_putstr("------------------------------------------\n");
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}