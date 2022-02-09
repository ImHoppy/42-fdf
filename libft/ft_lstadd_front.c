/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:42:33 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/17 16:59:39 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ajoute l’élément ’new’ au début de la liste.
 * @param alst L’adresse du pointeur vers le premier élément
de la liste.
 * @param new. L’adresse du pointeur vers l’élément à rajouter
à la liste.
 * @return None
 */
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst == NULL || new == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}
