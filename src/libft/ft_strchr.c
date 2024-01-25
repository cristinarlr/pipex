/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:42:58 by crramire          #+#    #+#             */
/*   Updated: 2023/03/22 15:20:11 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ccomp;

	ccomp = (char) c;
	while (*s && *s != ccomp)
		s++;
	if (*s == ccomp)
		return ((char *)s);
	return (0);
}

/* int main()
{
	char *source = "h\0la";	
	char *ptr = ft_strchr(source, 'h'); // my_function() devuelve un puntero
  	char *source = "alatortilla";	
	char *ptr = ft_strchr(source, 'l');

  	if (ptr == NULL)
		printf("La función devuelve un puntero nulo.\n");
	else
	printf("La función devuelve un puntero válido.\n");
	printf ("Puntero devuelto: %s\n", ptr);
	printf ("Address puntero devuelto: %p\n", (void *)ptr);
	return (0);
} */
