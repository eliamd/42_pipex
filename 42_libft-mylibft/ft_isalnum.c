/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:48:17 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:09:54 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The ft_isalnum function checks whether a character is a number or a letter.
 * It takes as argument an integer `c` representing the character to be checked.
 * It returns 1 if the character is a number or a letter and 0 otherwise.
 */

int	ft_isalnum(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) || \
	((c >= '0' && c <= '9')))
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
// 	assert(ft_isalnum('a') == isalnum('a'));
// 	printf("Etape 2 : Meme resultat pour 'a'\n");
// 	assert(ft_isalnum('Z') == isalnum('Z'));
// 	printf("Etape 3 : Meme resultat pour 'Z'\n");
// 	assert(ft_isalnum('1') == isalnum('1'));
// 	printf("Etape 4 : Meme resultat pour '1'\n");
// 	assert(ft_isalnum(' ') == isalnum(' '));
// 	printf("Etape 5 : Meme resultat pour ' '\n");
// 	assert(ft_isalnum(argv[1][0]) == isalnum(argv[1][0]));
// 	printf("Etape 6 : Meme resultat pour '%c'\n", argv[1][0]);
// 	printf("=== Test OK === \n");
// 	return (0);
// }
