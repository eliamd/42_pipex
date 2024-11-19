/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:37:49 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:18:17 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The ft_strlcpy function copies 'size' characters from the string
  string to the 'dest' string.

 * It takes three arguments: a 'dest' pointer to the destination string
   destination string, a 'src' pointer to the source string, and an unsigned
   int 'size' which is the number of characters to be copied.

 * It returns the total length of the 'src' string. This function is
   generally used to copy strings securely,
   avoiding buffer overflows.
 */

size_t	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	size_t	count;
	size_t	i;

	count = 0;
	while (src[count] != '\0')
		++count;
	if (size == 0)
		return (count);
	i = 0;
	while (src[i] != '\0' && i < ((size_t)size - 1))
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (count);
}

// #include  <string.h>
// #include  <stdio.h>
// #include  <unistd.h>

// int main(void)
// {
// 	char src[] = "Hello World!";
// 	char dest[6];
// 	int i;

// 	i = ft_strlcpy(dest, src, 12);
// 	printf("src: %s\n", src);
// 	printf("dest: %s\n", dest);
// 	printf("i: %d\n", i);
// 	return (0);
// }
