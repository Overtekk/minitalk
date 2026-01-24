/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:41:23 by roandrie          #+#    #+#             */
/*   Updated: 2026/01/24 09:44:11 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	print_signal(int bit)
{
	static int	i = 0;
	static char	c = 0;

	c = c << 1 | bit;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	get_signal(int signal)
{
	if (signal == SIGUSR1)
		print_signal(0);
	else
		print_signal(1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf(1, "[Server] PID: %d\n", getpid());
	sa.sa_handler = &get_signal;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
