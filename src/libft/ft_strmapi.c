/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:05:43 by Cristina          #+#    #+#             */
/*   Updated: 2024/01/19 12:39:40 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	ft_transform(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (c);
    else
        return (c + 1);
} */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (0);
	s2 = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!s2)
		return (0);
	while (s[i] != '\0')
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	return (s2);
}

/* int main()
{
    char *original = "Hola mundo";
    char *transformed = ft_strmapi(original, ft_transform);

    printf("Original: %s\n", original);
    printf("Transformed: %s\n", transformed);

    free(transformed);
    return (0);
} */
