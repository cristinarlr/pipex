/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:19:34 by Cristina          #+#    #+#             */
/*   Updated: 2023/03/15 23:51:21 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (n > 0)
	{
		if (*str1 != *str2)
			return ((*str1 - *str2));
		str1++;
		str2++;
		n--;
	}
	return (0);
}
/* int main ()
{
    const void *str1;
    const void *str2;
    size_t     n;

    n = 6;
    str1 = "hola.\200mundo";
    str2 = "hola.\0ispajo";
    printf("str1: %s\n", (char *) str1);
    printf("str2: %s\n", (char *) str2);
    printf("%d", ft_memcmp(str1, str2, n));
    return (0);
} */
