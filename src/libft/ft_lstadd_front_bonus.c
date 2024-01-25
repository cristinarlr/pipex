/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:43:47 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/17 09:20:04 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new -> next = *lst;
	*lst = new;
}

/* 
int	main()
{
	t_list	*head;
	t_list	*new;

	head = ft_lstnew("hola");
	new = ft_lstnew("mundo");
	ft_lstadd_front(&head, new);
	//meter estos debajo de (*lst) -> next = new; en la función de arriba
	//printf("address nodo lst: %p\n", lst);
	//printf("address nodo lst: %p\n", new);
	return (0);
}*/
