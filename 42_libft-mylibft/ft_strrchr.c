/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:54:44 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:19:20 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strrchr finds the last occurrence of 'letter' in 'str'.
 * Takes 'str' (string) and 'letter' (character to search for).
 * Returns a pointer to the character found, or NULL.
 */

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	char			*temp_str;
	unsigned char	letter;
	char			*last;

	letter = (unsigned char)c;
	temp_str = (char *)s;
	i = 0;
	last = NULL;
	while (temp_str[i])
	{
		if ((unsigned char)temp_str[i] == letter)
			last = &temp_str[i];
		i++;
	}
	if (letter == '\0')
		return (&temp_str[i]);
	return (last);
}

// #include  <string.h>
// #include  <stdio.h>
// #include  <unistd.h>

// int main(void)
// {
// 	char *res = ft_strrchr("abbbbbbbb", 'a');

// 	printf("FAKE %s\n", res);
// 	char *res2 = strrchr("abbbbbbbb", 'a');

// 	printf("VRAI %s\n", res2);
// 	return (1);
// }
