/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:56:22 by crramire          #+#    #+#             */
/*   Updated: 2023/05/16 13:18:20 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(char format, va_list args)
{
	int		count;

	count = 0;
	if (format == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (format == '%')
		count = ft_print_char('%');
	else if (format == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		count = ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		count = ft_print_u_nbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count = ft_print_u_hex_nbr(va_arg(args, unsigned int), format);
	else if (format == 'p')
		count = ft_print_ptr(va_arg(args, unsigned long long));
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_print_format(format[i + 1], args);
			i += 2;
		}
		else
		{
			count += ft_print_char(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}

/* int main()
{
	char	c;
	char	*s;
	char *ptr = &c;
	int i;
	int d;
	unsigned int u;
	unsigned int x;
	unsigned int X;

	c = 'c';
	s = "probando un str";
	i = -4565;
	d = -4565;
	u = -5643;
	x = 286;
	X = 286;
	printf("En printf un caracter es: %c\n", c);
	ft_printf("En ft_printf un caracter es: %c\n", c);
	printf("------------------------------\n");
	printf("En printf un string es: %s\n", s);
	ft_printf("En ft_printf un string es: %s\n", s);
	printf("------------------------------\n");
	printf("En printf un puntero es: %s\n", s);
	ft_printf("En ft_printf un puntero es: %s\n", s);
	printf("------------------------------\n");
	printf("En printf un i es: %i\n", i);
	ft_printf("En ft_printf un i es: %i\n", i);
	printf("------------------------------\n");
	printf("En printf un d es: %d\n", d);
	ft_printf("En ft_printf un d es: %d\n", d);
	printf("------------------------------\n");
	printf("En printf un u es: %u\n", u);
	ft_printf("En ft_printf un u es: %u\n", u);
	printf("------------------------------\n");
	printf("En printf un u es: %x\n", x);
	ft_printf("En ft_printf un u es: %x\n", x);
	printf("------------------------------\n");
	printf("En printf un u es: %X\n", X);
	ft_printf("En ft_printf un u es: %X\n", X);
	printf("------------------------------\n");
	printf("En printf el valor del puntero es: %p\n", (void*)ptr);
	printf("En ft_printf el valor del puntero es: %p\n", (void*)ptr);
	printf("------------------------------\n");
 	printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("En printf si pongo más flags que argumentos: %X\n %s", X);
	ft_printf("En ft_printf si pongo más flags que argumentos: %X\n %s", X);
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("En printf si pongo más args que flags: %X\n %s", X, s, p);
	ft_printf("En ft_printf si pongo más args que flags: %X\n %s", X, s, p);
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("En printf si paso un NULL: %d", NULL);
	ft_printf("En ft_printf si paso un NULL: %d", NULL);
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	return (0);
} */
