/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:59:45 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/18 11:41:25 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Alloue (avec malloc(3)) et renvoie un nouvel
 * élément. la variable content est initialisée à
 * l’aide de la valeur du paramètre content. La
 * variable ’next’ est initialisée à NULL.
 * @param content Le contenu du nouvel élément.
 * @return Le nouvel element
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
