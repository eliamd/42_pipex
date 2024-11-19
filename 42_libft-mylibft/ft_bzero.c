/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:39:13 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:08:30 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The ft_bzero function fills the first 'n' bytes of the memory
 * area pointed to by 'pointer' with zeros.
 *
 * It takes two arguments: a pointer 'pointer' to the memory area
 * to be filled, and a size_t 'count' which is the size of the
 * memory area to be filled.
 *
 * It does not return anything. This function is generally used
 * to initialize a memory area to zero.
 */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// #include <string.h>
// #include <assert.h>
// #include <stdlib.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char	*str;
// 	char	*str2;

// 	(void)argv;
// 	assert(argc == 2);
// 	printf("Etape 1 : L'appel a un arguments\n");
// 	str = malloc(50);
// 	ft_bzero(str, 50);
// 	str2 = malloc(50);
// 	memset(str2, 0, 50);
// 	assert(memcmp(str, str2, 50) == 0);
// 	printf("Etape 2 : Meme resultat pour un bloc de 50 octets\n");
// 	str = malloc(100);
// 	ft_bzero(str, 100);
// 	str2 = malloc(100);
// 	memset(str2, 0, 100);
// 	assert(memcmp(str, str2, 100) == 0);
// 	printf("Etape 3 : Meme resultat pour un bloc de 100 octets\n");
// 	str = malloc(200);
// 	ft_bzero(str, 200);
// 	str2 = malloc(200);
// 	memset(str2, 0, 200);
// 	assert(memcmp(str, str2, 200) == 0);
// 	printf("Etape 4 : Meme resultat pour un bloc de 200 octets\n");
// 	str = malloc(500);
// 	ft_bzero(str, 500);
// 	str2 = malloc(500);
// 	memset(str2, 0, 500);
// 	assert(memcmp(str, str2, 500) == 0);
// 	printf("Etape 5 : Meme resultat pour un bloc de 500 octets\n");
// 	printf("=== Test OK === \n");
// 	return (0);
// }
