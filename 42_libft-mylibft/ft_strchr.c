/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:54:44 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:16:34 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The ft_strchr function finds the first occurrence of the
  character in the string 'str'.

 * It takes two arguments: a 'str' pointer to the string to be
  string to be processed and an int
  'letter' which is the character to be searched for.

 * It returns a pointer to the first corresponding character
  in 'str', or NULL if the character is not found.
*/

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			*temp_str;
	unsigned char	letter;

	letter = (unsigned char)c;
	temp_str = (char *)s;
	i = 0;
	while (temp_str[i])
	{
		if ((unsigned char)temp_str[i] == letter)
			return (&temp_str[i]);
		i++;
	}
	if (letter == '\0')
		return (&temp_str[i]);
	return (NULL);
}

// #include  <string.h>
// #include  <stdio.h>
// #include  <unistd.h>

// int main(void)
// {
// 	char *res = ft_strchr("Bonjour", '\0');

// 	printf("FAKE %s\n", res);
// 	char *res2 = strchr("Bonjour", '\0');

// 	printf("VRAI %s\n", res2);
// 	return (1);
// }
