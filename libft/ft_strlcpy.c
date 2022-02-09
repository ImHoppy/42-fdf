/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:34:46 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/09 15:00:18 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(src);
	if (i + 1 < dstsize)
	{
		j = -1;
		while (++j < i + 1)
			dst[j] = src[j];
	}
	else if (dstsize)
	{
		j = -1;
		while (++j < dstsize - 1)
			dst[j] = src[j];
		dst[j] = '\0';
	}
	return (i);
}
