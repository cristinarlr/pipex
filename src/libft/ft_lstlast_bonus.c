/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:03:42 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/17 09:36:01 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	size;
	int	count;

	if (!lst)
		return (0);
	count = 0;
	size = ft_lstsize(lst);
	while (count != size - 1)
	{
		count ++;
		lst = lst -> next;
	}
	return (lst);
}
