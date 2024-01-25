/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:37:34 by crramire          #+#    #+#             */
/*   Updated: 2024/01/19 12:38:10 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*ptr;

	cc = (unsigned char) c;
	ptr = (unsigned char *) s;
	while (n > 0)
	{
		if (*ptr == cc)
			return ((void *) ptr);
		ptr++;
		n--;
	}
	return (0);
}
