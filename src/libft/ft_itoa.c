/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:04:45 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/04 18:32:58 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*str;
	int			len;

	nb = n;
	len = ft_countdigits(nb);
	str = (char *)ft_calloc((ft_countdigits(n) + 1), sizeof(char));
	if (!str)
		return (0);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb >= 10)
	{
		str[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	str[--len] = nb + '0';
	return (str);
}

/* int main()
{
    int n;

    n = 2147483647;
    //n = -2147483648;
    printf("Con el num: %d\n Reservamos: %d\n", n, ft_countdigits(n));
    printf("str: %s", ft_itoa(n));
    return (0);
}
 */
