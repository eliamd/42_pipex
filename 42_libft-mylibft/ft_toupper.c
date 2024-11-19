/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:19:43 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:20:19 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The ft_toupper function converts a lowercase letter
   into uppercase if it is lowercase.

 * It takes one argument: a 'letter' character which is the
 letter to be converted.

 * It returns the character converted to uppercase if 'letter' is lowercase.
  otherwise it returns 'letter' as is.
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
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
// 	assert(ft_toupper('a') == toupper('a'));
// 	printf("Etape 2 : Meme resultat pour 'a'\n");
// 	assert(ft_toupper('Z') == toupper('Z'));
// 	printf("Etape 3 : Meme resultat pour 'Z'\n");
// 	assert(ft_toupper('1') == toupper('1'));
// 	printf("Etape 4 : Meme resultat pour '1'\n");
// 	assert(ft_toupper(' ') == toupper(' '));
// 	printf("Etape 5 : Meme resultat pour ' '\n");
// 	assert(ft_toupper(argv[1][0]) == toupper(argv[1][0]));
// 	printf("Etape 6 : Meme resultat pour '%c'\n", argv[1][0]);
// 	printf("=== Test OK === \n");
// 	return (0);
// }
