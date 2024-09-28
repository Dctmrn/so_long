/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:17:23 by marida-c          #+#    #+#             */
/*   Updated: 2023/11/14 16:40:07 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tbl;

	j = 0;
	tbl = malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (!tbl)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] != c && s[i])
			i++;
		if (*s && i)
		{
			tbl[j] = ft_substr(s, 0, i);
			if (!tbl[j++])
				return (NULL);
		}
		s = s + i;
	}
	tbl[j] = NULL;
	return (tbl);
}
