/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:30:04 by marida-c          #+#    #+#             */
/*   Updated: 2023/11/13 18:23:24 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	strlen;
	unsigned int	sizetotal;
	char			*dst;

	sizetotal = 0;
	if (!s)
		return (NULL);
	strlen = ft_strlen((char *)s);
	if (start > strlen)
		return (ft_strdup(""));
	s = s + start;
	while (s[sizetotal] && len--)
		sizetotal++;
	dst = malloc(sizeof(char) * (sizetotal + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, sizetotal + 1);
	return (dst);
}
