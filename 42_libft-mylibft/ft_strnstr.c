/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:20:52 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:19:11 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strnstr searches for 'little' in 'big' up to 'len' characters.
 * Takes 'big' (main string) and 'little' (substring).
 * Returns a pointer to the beginning of 'little' in 'big', or NULL.
 */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j] && (i + j) < len)
		{
			j++;
		}
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (0);
}

// #include  <string.h>
// #include  <stdio.h>
// #include  <unistd.h>

// int main(void)
// {
// 	char *res = strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 19);

// 	printf("VRAI %s\n", res);
// 	char *res2 = ft_strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 19);

// 	printf("FAKE %s\n", res2);
// 	return (1);
// }
