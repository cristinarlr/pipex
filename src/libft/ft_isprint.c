/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:45:15 by crramire          #+#    #+#             */
/*   Updated: 2023/03/08 13:21:21 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* int	main(void)
{
	char	c;

	c = 'Q';
	printf("Result printable %c is passed to isprint(): %d", c, ft_isprint(c));
	printf("\n");
	c = '\n';
	printf("Result printable %c is passed to isprint(): %d", c, ft_isprint(c));
	printf("\n");
	c = 'Q';
	printf("Result printable %c is passed to isprint(): %d", c, isprint(c));
	printf("\n");
	c = '\n';
	printf("Result printable %c is passed to isprint(): %d", c, isprint(c));
	return (0);
} */