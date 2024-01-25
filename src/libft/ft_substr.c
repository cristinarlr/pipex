/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:21:36 by Cristina          #+#    #+#             */
/*   Updated: 2024/01/19 12:39:58 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*subs;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s == 0)
		return (0);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > (s_len - start))
		len = s_len - start;
	subs = malloc(sizeof(char) * (len + 1));
	if (subs == 0)
		return (0);
	i = 0;
	while (s[start] != '\0' && len > 0)
	{
		subs[i++] = s[start++];
		len--;
	}
	subs[i] = '\0';
	return (subs);
}

/* int main ()
{
	char *s;

	s = "hola pollito de seta";
	printf("subs: %s\n", ft_substr(s, 5, 7));
	printf("subs: %s\n", ft_substr(s, 50, 7));
	printf("subs: %s\n", ft_substr(s, 10, 50));
	printf("subs: %s\n", ft_substr(s, 5, 0));
		return (0);
} */
