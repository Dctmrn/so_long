/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:40:24 by marida-c          #+#    #+#             */
/*   Updated: 2024/10/09 13:40:28 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	i;
	long	nb;
	long	sign;

	sign = 1;
	nb = 0;
	i = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (sign * nb);
}
