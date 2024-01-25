/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:37:51 by Cristina          #+#    #+#             */
/*   Updated: 2023/11/24 09:28:04 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*new_node;
	t_list	*new_list;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	aux = lst;
	while (aux)
	{
		new_node = ft_lstnew(f(aux->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, new_node);
		aux = aux->next;
	}
	return (new_list);
}
