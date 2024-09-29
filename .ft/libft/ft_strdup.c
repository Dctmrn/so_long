/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrn <mrn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:29 by marida-c          #+#    #+#             */
/*   Updated: 2024/09/29 06:32:58 by mrn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char *copy = malloc(len + 1); // +1 pour le caractère de fin '\0'
	if (!copy)
        return NULL; // Si malloc échoue, retournez NULL

    ft_strlcpy(copy, s, len +1); // Copiez la chaîne
    return copy;
}

