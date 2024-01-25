/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:44:31 by Cristina          #+#    #+#             */
/*   Updated: 2023/03/27 14:34:09 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t		i;
	int			flag;
	int			result;

	flag = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			flag = -1;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * flag);
}

/*
int	main ()
{
	char	*str;
	int	value_atoi;
	int	value_ft_atoi;

	str = "  -34 9";
	str = "123\b45";
	value_atoi = atoi(str) - 2;
	printf ("atoi num = %d\n", atoi(str));
	printf ("atoi value of rest (%d - 2) = %d\n\n", atoi(str), value_atoi);	
	value_ft_atoi = ft_atoi(str) - 2;
	printf ("ft_atoi num = %d\n", ft_atoi(str));
	printf ("ft_atoi value of rest (%d - 2) = %d\n", ft_atoi(str), value_ft_atoi);
	return (0);
} */
