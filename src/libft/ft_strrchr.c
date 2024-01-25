/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:16:35 by Cristina          #+#    #+#             */
/*   Updated: 2023/03/15 23:04:08 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ccomp;

	i = ft_strlen (s);
	ccomp = (unsigned char) c;
	while (i > 0 && s[i] != ccomp)
	{
		i--;
	}
	if (s[i] == ccomp)
		return ((char *) s + i);
	return (0);
}
/* int main()
{
	char *source = "hola";	
	char *ptr = ft_strrchr(source, 'l'); // my_function() devuelve un puntero
  
	printf ("Puntero devuelto: %s\n", ptr);

  	if (ptr == NULL)
		printf ("La función devuelve un puntero nulo.\n");
	else
		printf ("La función devuelve un puntero válido.\n");
	printf ("Puntero devuelto: %s\n", ptr);
	printf ("Address puntero devuelto: %p\n", (void *)ptr);
	return (0);
} */