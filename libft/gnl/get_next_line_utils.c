/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:59:25 by hoppy             #+#    #+#             */
/*   Updated: 2022/03/03 16:37:08 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	int	n;

	n = 0;
	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}

int	gnl_str_eol(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strncpy(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*result;
	int		size1;
	int		size2;

	size1 = gnl_strlen(s1);
	size2 = gnl_strlen(s2);
	result = malloc(sizeof(char) * (size1 + size2) + 1);
	if (!result)
		return (NULL);
	gnl_strncpy(result, s1, size1);
	gnl_strncpy(result + size1, s2, size2);
	if (s1)
		free(s1);
	return (result);
}
