/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:32:02 by mbraets           #+#    #+#             */
/*   Updated: 2021/11/23 16:33:23 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;

	i = -1;
	str = (char *)s;
	while (str[++i])
		if (str[i] == (char)c)
			return (str + i);
	if (str[i] == (char)c)
		return (str + i);
	return (0);
}
