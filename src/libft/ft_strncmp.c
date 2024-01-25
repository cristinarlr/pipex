/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:33:23 by crramire          #+#    #+#             */
/*   Updated: 2023/04/11 09:52:57 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
	{
		if ((unsigned char) *s1 != (unsigned char) *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
		n--;
	}
	if (n > 0 && (*s1 == '\0' || *s2 == '\0'))
		return ((unsigned char) *s1 - (unsigned char) *s2);
	return (0);
}
/*
int	main()
{
	char	*string1;
	char	*string2;
	char	*string3;
	size_t	n;

	n = 6;
	string1 = "";
	string2 = "hola.b";
	string3 = "hol";
	printf("%d\n", strncmp(string1, string2, 0)); 
	printf("%d\n", strncmp(string1, string2, 4));
	printf("%d\n", strncmp(string1, string2, 6));
	printf("%d\n", strncmp(string1, string3, 6));

	printf("%d\n", ft_strncmp(string1, string2, 0)); 
	printf("%d\n", ft_strncmp(string1, string2, 4));
	printf("%d\n", ft_strncmp(string1, string2, 6));
	printf("%d\n\n", ft_strncmp(string1, string3, 6));

	printf("TESTS forzando el code:\n");
	printf("s1: %s\n", string1);
	printf("s2: %s\n", string2);
	printf("n: %lu\n", n);
	if (ft_strncmp(string1, string2, n) > 0)
		printf("s1: %s es mayor que s2: %s\n", string1, string2);
	else if (ft_strncmp(string1, string2, n) < 0)
		printf("s1: %s es menor que s2: %s\n", string1, string2);
	else if (ft_strncmp(string1, string2, n) == 0)
		printf("s1: %s es igual que s2: %s\n", string1, string2);
}*/
