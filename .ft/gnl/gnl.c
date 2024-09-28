/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrn <mrn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:53:40 by marida-c          #+#    #+#             */
/*   Updated: 2024/09/10 14:54:09 by mrn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	check_new_line(char *new)
{
	int	i;

	i = -1;
	if (!new)
		return (0);
	while (new[++i])
		if (new[i] == '\n')
			return (i + 1);
	return (0);
}

int	read_buffer(int fd, char *buffer)
{
	if (buffer[0] != '\0')
		return (1);
	if (read(fd, buffer, BUFFER_SIZE) > 0)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			new_line;
	int			i;
	static char	buffer[BUFFER_SIZE];

	line = NULL;
	while ((!check_new_line(line)) && read_buffer(fd, (char *)buffer) > 0)
	{
		new_line = check_new_line(buffer);
		line = ft_strrjoin(line, buffer, new_line);
		if (!line)
			return (NULL);
		i = -1;
		while (++i < BUFFER_SIZE)
		{
			if (new_line && new_line + i < BUFFER_SIZE)
				buffer[i] = buffer[i + new_line];
			else
				buffer[i] = '\0';
		}
	}
	return (line);
}
