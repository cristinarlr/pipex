/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:44:25 by crramire          #+#    #+#             */
/*   Updated: 2023/04/11 09:39:45 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dst;

	ptr_src = (const unsigned char *) src;
	ptr_dst = (unsigned char *) dst;
	if (!dst && !src)
		return (NULL);
	if (len == 0 || ptr_src == ptr_dst)
		return (dst);
	if (ptr_src < ptr_dst)
	{
		while (len--)
			*(ptr_dst + len) = *(ptr_src + len);
	}
	else
	{
		while (len--)
			*ptr_dst++ = *ptr_src++;
	}
	return (dst);
}

/* int	main()
{ 
	// test 1: null pointers
	char source[] = "";
	char destination[] = "gominolas\n";
	printf("%s", destination);
	ft_memmove(destination, source, 3);
	printf("%s", destination);
 	// test 2: len==0
	char source[] = "pipa\n";
	char destination[] = "gominolas\n";
	printf("%s", destination);
	ft_memmove(destination, source, 0);
	printf("%s", destination);

	// test 2.1: source = dest
	char source[] = "pipa\n";
	
	printf("%s", source);
	ft_memmove(source, source, 0);
	printf("%s", source);

	// test 3: size_src < size_dst
	char source[] = "pipa\n";
	char destination[] = "gominolas\n";
	printf("%s", destination);
	ft_memmove(destination, source, 3);
	printf("%s", destination);

	// test 4: size_src > size_dst
	char source[] = "gominolas\n";
	char destination[] = "pipa\n";
	printf("%s", destination);
	ft_memmove(destination, source, 3);
	printf("%s", destination);

	// test 5: size_src > size_dst y len = overflow
	char source[] = "gominolas\n";
	char destination[] = "pipa\n";
	printf("%s", destination);
	ft_memmove(destination, source, 20);
	printf("%s", destination); *
	return (0);
} */
