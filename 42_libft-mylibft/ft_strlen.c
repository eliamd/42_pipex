/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:48:17 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:18:31 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The ft_strlen function calculates the length of a character string.
 * It takes a string `str` as argument.
 * It returns the number of characters in the string,
  excluding the end-of-string character ('\0').
 */

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <assert.h>
// #include <ctype.h>
// #include <string.h>

// int	main(int argc, char **argv)
// {
// 	assert(argc == 2);
// 	printf("Etape 1 : L'appel a un arguments\n");
// 	assert(ft_strlen("Hello, World!") == strlen("Hello, World!"));
// 	printf("Etape 2 : Meme longueur pour 'Hello, World!'\n");
// 	assert(ft_strlen("") == strlen(""));
// 	printf("Etape 3 : Meme longueur pour une chaine vide\n");
// 	assert(ft_strlen("1234567890") == strlen("1234567890"));
// 	printf("Etape 4 : Meme longueur pour '1234567890'\n");
// 	assert(ft_strlen("abcdefghijklmno") == strlen("abcdefghijklmno"));
// 	printf("Etape 5 : Meme longueur pour 'abcdefghijklmno'\n");
// 	assert(ft_strlen("ABCDEFGHIJKLMNO") == strlen("ABCDEFGHIJKLMNO"));
// 	printf("Etape 6 : Meme longueur pour 'ABCDEFGHIJKLMNO'\n");
// 	assert(ft_strlen(argv[1]) == (int)strlen(argv[1]));
// 	printf("Etape 7 : Meme longueur pour '%s'\n", argv[1]);
// 	printf("=== Test OK === \n");
// 	return (0);
// }
