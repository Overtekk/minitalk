/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:00:27 by roandrie          #+#    #+#             */
/*   Updated: 2026/01/23 13:14:17 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char* string_to_binary(char* str)
{
	if (str == NULL)
		return (0);
	int	i;
	int j;
	size_t	len;
	char	*str_binary;
	len = ft_strlen(str);
	str_binary = malloc((len * 8) + 1);
	if (str_binary == NULL)
		return (NULL);
	i = 0;
	while(str[i] != '\0')
	{

	}

	return (str_binary);
}



int main(int argc, char **argv)
{
	if (argc != 3)
		return (ft_printf(2, "Error: Invalid arguments"), 2);

	int server_pid;
	char *str;

	str = string_to_binary(argv[2]);

	server_pid = ft_atoi(argv[1]);
	kill(server_pid, SIGUSR1);
	return (0);
}
