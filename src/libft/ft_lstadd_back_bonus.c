/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:47:58 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/17 09:14:12 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!new | !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux = *lst;
	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	aux->next = new;
}
/* int    main()
 {
    t_list	*head;
	t_list	*newfront;
    t_list	*newback;

	head = ft_lstnew("hola");
	newfront = ft_lstnew("delante ");
    newback = ft_lstnew(" detras");
	ft_lstadd_front(&head, newfront);
    printf("lst %s\n", head);

    return (0);
 } */
