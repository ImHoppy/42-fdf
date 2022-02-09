/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:36:20 by mbraets           #+#    #+#             */
/*   Updated: 2021/12/01 12:33:12 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int c)
{
	char	*result;
	long	n;
	int		len;

	n = c;
	len = ft_intlen(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	if (n == 0)
		result[0] = '0';
	while (n > 0)
	{
		result[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (result);
}
