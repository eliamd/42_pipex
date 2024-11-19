/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:13:33 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:16:44 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strdup duplicates a string.
 * Takes 'src' (pointer to source string).
 * Returns a pointer to the new duplicated string.
 */

char	*ft_strdup(const char *s)
{
	char	*strduped;
	int		i;
	int		length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	strduped = malloc((length + 1) * sizeof(char));
	if (!strduped)
		return (NULL);
	i = 0;
	while (i < length)
	{
		strduped[i] = s[i];
		i++;
	}
	strduped[i] = '\0';
	return (strduped);
}

// #include <stdlib.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*src = "Hello, world!";
// 	char	*duplicated;

// 	duplicated = ft_strdup(src);
// 	printf("Chaîne source : %s\n", src);
// 	printf("Chaîne dupliquée : %s\n", duplicated);
// 	free(duplicated);
// 	return (0);
// }
