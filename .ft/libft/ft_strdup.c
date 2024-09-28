/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:29 by marida-c          #+#    #+#             */
/*   Updated: 2023/11/13 14:23:53 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	dst = (char *)malloc(i + 1 * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s, i + 1);
	return (dst);
}
