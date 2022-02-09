/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:57:50 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/17 17:07:23 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Itère sur la liste lst et applique la fonction f au 
contenu de chaque élément. Crée une nouvelle liste 
résultant des applications successives de f. la 
fonction del est la pour detruire le contenu d un 
element si necessaire 
 * @param lst L’adresse du pointeur vers un élément.
 * @param f L’adresse de la fonction à appliquer.
 * @return La nouvelle liste. NULL si l’allocation échoue.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
