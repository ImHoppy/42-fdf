/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:53:17 by mbraets           #+#    #+#             */
/*   Updated: 2021/11/23 16:33:43 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s) + 1;
	str = (char *)s;
	while (--size != 0)
	{
		if (str[size] == (char)c)
			return (str + size);
	}
	if (str[size] == (char)c)
		return (str + size);
	return (0);
}
