/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:08:56 by mbraets           #+#    #+#             */
/*   Updated: 2021/11/24 12:15:03 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	size_t			i;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < len)
	{
		if (dst > src)
		{
			len--;
			temp_dst[len] = temp_src[len];
		}
		else
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}
