/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:35:23 by mbraets           #+#    #+#             */
/*   Updated: 2021/11/23 15:12:05 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	temp_dst = (unsigned char *) dst;
	temp_src = (unsigned char *) src;
	while (n > 0)
	{
		*temp_dst++ = *temp_src++;
		n--;
	}	
	return (dst);
}
