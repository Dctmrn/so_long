/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usgnint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:21:55 by marida-c          #+#    #+#             */
/*   Updated: 2023/11/29 12:22:01 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_usgnint(unsigned int nb)
{
	unsigned int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_print_usgnint(nb / 10);
		count += ft_print_usgnint(nb % 10);
	}
	else if (nb <= 9)
		count += ft_print_char(nb + '0');
	return (count);
}
