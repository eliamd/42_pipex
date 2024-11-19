/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:48:17 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:10:22 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The ft_isascii function checks whether a character is within the ASCII range.
 * It takes as argument an integer `c` representing the character to be checked.
 * It returns 1 if the character is in ASCII
 * (0 to 127 inclusive) and 0 otherwise.
 */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <assert.h>
// #include <ctype.h>

// int	main(int argc, char **argv)
// {
// 	assert(argc == 2);
// 	printf("Etape 1 : L'appel a un arguments\n");
// 	assert(ft_isascii('a') == isascii('a'));
// 	printf("Etape 2 : Meme resultat pour 'a'\n");
// 	assert(ft_isascii('Z') == isascii('Z'));
// 	printf("Etape 3 : Meme resultat pour 'Z'\n");
// 	assert(ft_isascii('1') == isascii('1'));
// 	printf("Etape 4 : Meme resultat pour '1'\n");
// 	assert(ft_isascii(' ') == isascii(' '));
// 	printf("Etape 5 : Meme resultat pour ' '\n");
// 	assert(ft_isascii(argv[1][0]) == isascii(argv[1][0]));
// 	printf("Etape 6 : Meme resultat pour '%c'\n", argv[1][0]);
// 	printf("=== Test OK === \n");
// 	return (0);
// }
