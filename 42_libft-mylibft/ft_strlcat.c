/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:22:17 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:17:55 by edetoh           ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, \
	size_t size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		++src_len;
	while (dst[dest_len] != '\0' && dest_len < size)
		++dest_len;
	if (dest_len == size)
		return (dest_len + src_len);
	i = 0;
	while (i < src_len && (dest_len + i + 1) < size)
	{
		dst[dest_len + i] = src[i];
		++i;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// int main(void)
// {
// 	char src[7] = "123456";
// 	char dest[7] = "123456";
// 	int i;

// 	printf("src: %s\n", src);
// 	i = ft_strlcpy(dest, src, 14);
// 	printf("src: %s\n", src);
// 	printf("dest: %s\n", dest);
// 	printf("i: %d\n", i);
// 	return (0);
// }
