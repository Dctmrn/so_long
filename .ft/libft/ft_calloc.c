/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:58:41 by marida-c          #+#    #+#             */
/*   Updated: 2023/11/15 13:51:44 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int				x;
	unsigned char	*dest;

	dest = 0;
	x = nmemb * size;
	if (size && x / size != nmemb)
		return (NULL);
	dest = malloc(x);
	if (!dest)
		return (NULL);
	ft_bzero(dest, x);
	return ((void *)dest);
}
