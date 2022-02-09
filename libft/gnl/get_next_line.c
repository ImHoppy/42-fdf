/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:59:35 by hoppy             #+#    #+#             */
/*   Updated: 2022/02/09 15:08:21 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*linejoin(char *buffer, char *line, int len)
{
	char	*save;

	save = malloc(sizeof(char) * (len + 1));
	if (!save)
		return (NULL);
	gnl_strncpy(save, buffer, len);
	line = gnl_strjoin(line, save);
	free(save);
	return (line);
}

static char	*while_read(char *b, int count, int fd, int len)
{
	char	*line;
	int		i;

	line = NULL;
	while (count || b[0] != '\0')
	{
		b[count + len] = '\0';
		i = gnl_str_eol(b);
		if (i == -1)
		{
			line = linejoin(b, line, len + count);
			if (!line)
				return (NULL);
			count = read(fd, b, BUFFER_SIZE);
			len = 0;
		}
		else
		{
			line = linejoin(b, line, i + 1);
			if (!line)
				return (NULL);
			return (gnl_strncpy(b, b + i + 1, BUFFER_SIZE - i - 1), line);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	int			count;
	char		*line;
	int			len;

	if (fd < 0)
		return (NULL);
	len = gnl_strlen(buffer[fd]);
	count = read(fd, buffer[fd] + len, BUFFER_SIZE - len);
	if (count == -1)
		return (NULL);
	line = while_read(buffer[fd], count, fd, len);
	return (line);
}
