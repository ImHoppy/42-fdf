/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:24:39 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/17 17:06:44 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Supprime et libère la mémoire de l’élément passé en 
 * paramètre, et de tous les élements qui suivent, à 
 * l’aide de del et de free(3). 
 * Enfin, le pointeur initial doit être mis à NULL.
 * @param lst L’adresse du pointeur vers un élément.
 * @param del L’adresse de la fonction permettant de
supprimer le contenu d’un élément.
 * @return None
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*old;

	list = *lst;
	while (list != NULL)
	{
		old = list->next;
		ft_lstdelone(list, (*del));
		list = old;
	}
	*lst = 0;
}
