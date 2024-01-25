/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:57:22 by crramire          #+#    #+#             */
/*   Updated: 2024/01/19 12:39:49 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	size_t	ltrim;

	ltrim = 0;
	while (s1[ltrim] != '\0')
	{
		if (ft_strchr(set, s1[ltrim]) != 0)
			ltrim++;
		else
			break ;
	}
	return (ltrim);
}

static int	ft_end(char const *s1, char const *set)
{
	size_t	rtrim;

	rtrim = ft_strlen(s1);
	while (rtrim > 0)
	{
		if (ft_strchr(set, s1[rtrim]) != 0)
			rtrim--;
		else
			break ;
	}
	return (rtrim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (s1 == 0 || set == 0)
		return (0);
	start = ft_start(s1, set);
	end = ft_end(s1, set) - start + 1;
	trimmed = ft_substr(s1, start, end);
	return ((char *) trimmed);
}

/* int main()
{
	char	s[30000] = "hola";
	char	*set;

	set = "la";
	printf("valor de strlen: %zu\n", ft_strlen(s));
	printf("trim: %s", ft_strtrim(s, set));
	return (0);
} */
