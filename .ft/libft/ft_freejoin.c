/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:41:00 by marida-c          #+#    #+#             */
/*   Updated: 2024/10/09 13:41:02 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freejoin(char *s1, char *s2, int sizeS1, int sizeS2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	dest = malloc((sizeS1 + sizeS2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < sizeS1)
	{
		dest[i] = s1[i];
		i++;
	}
	while (j < sizeS2)
	{
		dest[i + j] = s2[j];
		j++;
	}
	free(s1);
	dest[i + j] = '\0';
	return (dest);
}
