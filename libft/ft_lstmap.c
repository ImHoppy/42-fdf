/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:01:43 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/25 15:30:16 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Itère sur la liste lst et applique la fonction f au 
contenu de chaque élément. Crée une nouvelle liste 
résultant des applications successives de f. La 
fonction del est la pour detruire le contenu d'un 
element si necessaire.
 * @param lst L’adresse du pointeur vers un élément.
 * @param del L’adresse de la fonction à appliquer.
 * @return La nouvelle liste. NULL si l’allocation échoue.
 * @deprecated malloc, free
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;

	if (!lst || !f)
		return (0);
	list = ft_lstnew((*f)(lst->content));
	if (!list)
	{
		ft_lstclear(&list, del);
		return (0);
	}
	list->next = ft_lstmap(lst->next, f, del);
	return (list);
}
