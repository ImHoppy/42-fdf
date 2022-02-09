/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:02:16 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/17 17:00:24 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compte le nombre d’éléments de la liste.
 * @param lst Le début de la liste.
 * @return Taille de la liste.
 */
int	ft_lstsize(t_list *lst)
{
	int		n;

	n = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}
