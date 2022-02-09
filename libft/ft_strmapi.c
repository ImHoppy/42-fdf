/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:00:49 by mbraets           #+#    #+#             */
/*   Updated: 2021/11/29 12:38:20 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	result = NULL;
	if (s && f)
	{
		result = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
		if (!result)
			return (NULL);
		i = 0;
		while (i < ft_strlen(s))
		{
			result[i] = (*f)(i, s[i]);
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
