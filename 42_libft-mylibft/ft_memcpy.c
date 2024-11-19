/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:54:04 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:14:31 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The ft_memcpy function copies 'count' bytes from the 'src' memory area
 memory area to the 'dest' memory area.

 * It takes three arguments: a 'dest' pointer to the destination memory area
  destination memory area, a 'src' pointer to the source memory area, and a
  size_t 'count' which is the number of bytes to be copied.

 * Returns a pointer to the destination memory area. This
  This function is generally used to copy blocks of memory.
 */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrsrc;
	unsigned char	*ptrdest;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	ptrsrc = (unsigned char *)src;
	ptrdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (ptrdest);
}

// #include <string.h>
// #include <assert.h>
// #include <stdlib.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;
// 	char	str[8] = "bonjour";
// 	char	str2[8] = "bonsoir";

// 	printf("av : str : %s\n", str);
// 	printf("av : str2 : %s\n", str2);

// 	ft_memcpy(str2, str, 8);

// 	printf("ap : str : %s\n", str);
// 	printf("ap : str2 : %s\n", str2);

// 	printf("=== Test OK === \n");
// 	return (0);
// }
