/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:54:36 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/25 12:27:13 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ajoute l’élément new à la fin de la liste.
 * @param alst L’adresse du pointeur vers le premier élément
de la liste.
 * @param new  L’adresse du pointeur vers l’élément à rajouter
à la liste.
 * @return None
 */
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst == NULL || new == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	last = ft_lstlast(*alst);
	last->next = new;
}
