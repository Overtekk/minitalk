/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:00:27 by roandrie          #+#    #+#             */
/*   Updated: 2026/01/24 09:48:04 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	send_bytes(char c, int server_pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(1000);
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	if (argc != 3)
		return (ft_printf(2, "Error: Usage = './client <pid> <message>'"), 2);
	i = 0;
	server_pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		send_bytes(argv[2][i], server_pid);
		i++;
	}
	send_bytes('\0', server_pid);
	return (0);
}
