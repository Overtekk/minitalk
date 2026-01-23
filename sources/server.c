/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:41:23 by roandrie          #+#    #+#             */
/*   Updated: 2026/01/23 12:55:58 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void reaction(int signal)
{
	if (signal == SIGUSR1)
		ft_printf(1, "Signal received!");
}

int main()
{
	int	pid;

	pid = getpid();
	ft_printf(1, "[Server] PID: %d\n", pid);

	signal(SIGUSR1, reaction);

	while(1)
	{
		pause();
	}
	return (0);
}
