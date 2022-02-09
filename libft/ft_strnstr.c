/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:44:51 by mbraets           #+#    #+#             */
/*   Updated: 2021/11/23 18:23:51 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	size_t			needle_size;
	char			*temp_haystack;

	i = 0;
	needle_size = ft_strlen(needle);
	temp_haystack = (char *)haystack;
	if (needle_size == 0 || haystack == needle)
		return (temp_haystack);
	while (i < len && temp_haystack[i] != '\0')
	{
		j = 0;
		while (temp_haystack[i + j] != '\0' && needle[j] != '\0'
			&& temp_haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (needle_size == j)
			return (temp_haystack + i);
		i++;
	}
	return (0);
}
