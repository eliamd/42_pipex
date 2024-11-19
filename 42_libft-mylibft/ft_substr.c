/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:52:31 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:19:41 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_substr extracts a substring from 'str'.
 * Takes 'str' (source string), 'start' (start index),
 * and 'len' (length of substring). Returns the substring.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	k;

	if (start >= (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	sub_str = malloc((len + 1) * sizeof(char));
	if (!sub_str || !s)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (i >= start && k < len)
		{
			sub_str[k] = s[i];
			k++;
		}
		i++;
	}
	sub_str[k] = '\0';
	return (sub_str);
}

// #include  <string.h>
// #include  <stdio.h>
// #include  <unistd.h>

// int main(void)
// {
// 	char *str = "1234567890";
// 	unsigned int start = 100;
// 	size_t lensent = 100;

// 	char *res = ft_substr(str, start, lensent);

// 	printf("===== RESULT =====\n%s\n==================", res);

// 	return (1);
// }
