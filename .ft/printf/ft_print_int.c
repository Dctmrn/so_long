/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:21:41 by marida-c          #+#    #+#             */
/*   Updated: 2023/11/20 17:21:44 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int nb)
{
	int		count;

	count = 0;
	if (nb == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (nb < 0)
	{
		count += ft_print_char('-');
		nb = -nb;
	}
	if (nb / 10)
		count += ft_print_int(nb / 10);
	count += ft_print_char(nb % 10 + '0');
	return (count);
}
