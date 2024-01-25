/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:58:18 by crramire          #+#    #+#             */
/*   Updated: 2023/04/11 10:13:39 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ccatstr;
	size_t	ccatlen;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	ccatlen = (ft_strlen(s1) + ft_strlen(s2));
	ccatstr = malloc(ccatlen + 1);
	if (ccatstr == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		ccatstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ccatstr[i++] = s2[j++];
	}
	ccatstr[i] = '\0';
	return (ccatstr);
}

/* int main ()
{
	char	*s1;
	char	*s2;

	s1 = "tortilla";
	s2 = " de patatas";
	printf("ccat: %s\n", ft_strjoin(s1,s2));
    ft_strjoin("abc", "");
	return (0);
}	 */
