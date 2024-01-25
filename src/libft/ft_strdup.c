/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:03:56 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/11 11:28:24 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*scpy;

	scpy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (scpy == NULL)
		return (NULL);
	ft_memcpy(scpy, s, ft_strlen(s) + 1);
	return (scpy);
}

/* int main() 
{
char *str;

str = "palomitas";
printf("size of str:%lu\n", sizeof(str));
printf("strlen of str:%lu\n", ft_strlen(str));
printf("address original str:%d\n\n", &str);
printf("size of str:%lu\n", sizeof(ft_strdup(str)));
printf("strlen of str:%lu\n", ft_strlen(ft_strdup(str)));
printf("address new str:%d\n\n", &str);
return(0);
} */
