/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:44:37 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/17 09:42:09 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		count++;
		lst = lst -> next;
	}
	return (count);
}
/* 
int	main()
{
	t_list	*head;
	t_list	*new;

	head = ft_lstnew("hola");
    new = ft_lstnew("mundo");
    printf("#nodos = %d\n", ft_lstsize(head));
	ft_lstadd_front(&head, new);
    printf("#nodos después de lstadd_front= %d\n", ft_lstsize(head));
	return (0);
} */
