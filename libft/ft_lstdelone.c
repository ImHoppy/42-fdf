/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoppy <hoppy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:23:05 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/26 17:26:29 by hoppy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Libère la mémoire de l’élément passé en argument 
en utilisant la fonction del puis avec free(3). La 
mémoire de next ne doit pas être free.
 * @param lst L’élement à free
 * @param del L’adresse de la fonction permettant de
supprimer le contenu de l’élement.
 * @return None
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
}
