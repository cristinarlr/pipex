/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:23:12 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/06 18:26:18 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_transform(unsigned int i, char *s)
{
	(void)i;
	s[i] = 'x';
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
int	main()
{
	char str[] = "Hello World!";
    printf("str antes: %s\n", str);
	ft_striteri(str, ft_transform);
    printf("str después: %s\n", str);
	return (0);
}*/
