/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:17:11 by roandrie          #+#    #+#             */
/*   Updated: 2026/01/23 13:34:11 by roandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int is_valid_base(char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (len < 2 || base == NULL)
		return (0);
	int	i;
	int	j;
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int ft_atoi_base(char *str, char *base)
{
	if (is_valid_base == 0)
		return (0);
}
