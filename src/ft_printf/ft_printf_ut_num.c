/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ut_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:22:47 by crramire          #+#    #+#             */
/*   Updated: 2023/05/16 14:21:32 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_print_nbr(int num)
{
	int	count;

	count = 0;
	ft_putnbr(num);
	if (num <= 0)
		count++;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	ft_print_u_nbr(unsigned int num)
{
	int		count;
	char	c;

	count = 0;
	if (num < 10)
	{
		c = num + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

void	ft_convert_to_hex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_convert_to_hex(n / 16, format);
		ft_convert_to_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_print_char(n + '0');
		else
		{
			if (format == 'x')
				ft_print_char((n - 10) + 'a');
			if (format == 'X')
				ft_print_char((n - 10) + 'A');
		}
	}
}

int	ft_print_u_hex_nbr(unsigned int num, const char format)
{
	int	count;

	count = 0;
	ft_convert_to_hex(num, format);
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 16;
		count++;
	}
	return (count);
}
