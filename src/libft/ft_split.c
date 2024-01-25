/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:35:34 by crramire          #+#    #+#             */
/*   Updated: 2024/01/19 12:39:02 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_freearray(char **array)
{
	size_t	raw;

	raw = 0;
	while (array[raw])
	{
		free(array[raw]);
		raw++;
	}
	free(array);
	return (0);
}

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_allocateword(char const *s, int j, int i, char **array)
{
	char	*word;

	word = (char *)ft_calloc((j + 1), sizeof(char));
	if (!word)
		return (0);
	ft_strlcpy(word, (char *)&s[i - j], j + 1);
	array[0] = word;
	return (array);
}

static char	**ft_addwords(char const *s, char c, int y, char **array)
{
	int		i;
	int		j;
	int		raw;

	i = 0;
	j = 0;
	raw = 0;
	while (i < (int)(ft_strlen(s) + 1))
	{
		if (s[i] != c && s[i] != '\0')
			j++;
		else
		{
			while (raw < y && j > 0)
			{
				if (!ft_allocateword(s, j, i, array + raw))
					return (0);
				raw++;
				j = 0;
			}
		}
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	y;
	char	**array;

	if (!s)
		return (0);
	y = ft_countwords(s, c) + 1;
	array = (char **)ft_calloc(y, sizeof(char *));
	if (!array)
		return (0);
	if (!ft_addwords(s, c, y, array))
	{
		ft_freearray(array);
		return (0);
	}
	return (array);
}

/* int main()
{
    const char *s;
    char       c;
    char       **array;
    int        x;

    s = "..i.cant...believe..this..split.fantasy..";
    c = '.';
    array = ft_split(s, c);
    x= 0;
    while(array[x])
    {
        printf("%s\n", array[x]);
        x++;
    }
    return(0);
} */
