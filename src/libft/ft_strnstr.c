/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:57:13 by Cristina          #+#    #+#             */
/*   Updated: 2023/03/16 13:42:07 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 @param haystack the string to search in
@param needle the string to find
@param len the maximum number of characters to search
 */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0' || (needle == haystack))
		return ((char *) haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (0);
	if (len == 0 || len < ft_strlen(needle))
		return (0);
	while (i < len)
	{
		while (haystack[i] == needle[j] && (i < len))
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *) haystack + (i - j));
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (0);
}
/*
int main ()
{
    const char *hay;
    const char *needle;
    size_t     n;

    n = 50;
    hay = "soy un gran pajar de palabras";
    needle = "un";
    printf("%s\n", strnstr(hay, hay, n));
    printf("%s\n", strnstr(hay, needle, n));
    printf("%s\n", ft_strnstr(hay, hay, n));
    printf("%s\n", ft_strnstr(hay, needle, n));
    return (0);
}*/
