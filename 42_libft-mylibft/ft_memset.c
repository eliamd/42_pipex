/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:05:01 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:15:25 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The ft_memset function fills the first 'n' bytes of the memory area
  pointed to by 'ptr' with byte 'c'.

 * It takes three arguments: a pointer 'ptr' to the memory area to be filled,
  an int 'c' which is converted to an unsigned
  char and used to fill the memory area
  and a size_t 'n' which is the size of the memory area to be filled.

 * It returns a pointer to the filled memory area.
  This function is generally used to initialize
   a memory area to a specific value.
 */

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

// #include <string.h>
// #include <assert.h>
// #include <stdlib.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char	*str;
// 	char	*str2;

// 	assert(argc == 2);
// 	printf("Etape 1 : L'appel a un arguments\n");
// 	str = ft_memset(malloc(50), 'a', 50);
// 	str2 = memset(malloc(50), 'a', 50);
// 	assert(memcmp(str, str2, 50) == 0);
// 	printf("Etape 2 : Meme resultat pour 'a'\n");
// 	str = ft_memset(malloc(50), 'Z', 50);
// 	str2 = memset(malloc(50), 'Z', 50);
// 	assert(memcmp(str, str2, 50) == 0);
// 	printf("Etape 3 : Meme resultat pour 'Z'\n");
// 	str = ft_memset(malloc(50), '1', 50);
// 	str2 = memset(malloc(50), '1', 50);
// 	assert(memcmp(str, str2, 50) == 0);
// 	printf("Etape 4 : Meme resultat pour '1'\n");
// 	str = ft_memset(malloc(50), argv[1][0], 50);
// 	str2 = memset(malloc(50), argv[1][0], 50);
// 	assert(memcmp(str, str2, 50) == 0);
// 	printf("Etape 5 : Meme resultat pour '%c'\n", argv[1][0]);
// 	printf("=== Test OK === \n");
// 	return (0);
// }
