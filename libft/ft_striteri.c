/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:40:13 by mbraets           #+#    #+#             */
/*   Updated: 2021/11/30 17:02:02 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	len;

	i = 0;
	if (s != NULL && f)
	{
		len = ft_strlen(s);
		while (i < len)
		{
			(*f)(i, s);
			i++;
			s++;
		}
	}
}
