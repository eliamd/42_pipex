/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:08:16 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:14:50 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The ft_memmove function copies 'count' bytes from the 'src' memory area to the
  memory area 'dest', even if these areas overlap.

 * It takes three arguments: a 'dest' pointer to the destination memory area
 a 'src' pointer to the source memory area, and a 'count' size_t
 which is the number of bytes to be copied.

 * It returns a pointer to the destination memory area.
 This function is generally used to move blocks of memory.
 */

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptrsrc;
	unsigned char	*ptrdest;

	ptrsrc = (unsigned char *)src;
	ptrdest = (unsigned char *)dst;
	if (ptrdest == ptrsrc || n == 0)
		return (dst);
	if (ptrdest > ptrsrc && ptrdest < (ptrsrc + n))
	{
		while (n > 0)
		{
			n--;
			ptrdest[n] = ptrsrc[n];
		}
	}
	else
	{
		ft_memcpy(dst, src, n);
	}
	return (ptrdest);
}

// #include <string.h>
// #include <assert.h>
// #include <stdlib.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;
// 	char	str[8] = "bonjour";
// 	char	str2[8] = "bonsoir";

// 	printf("av : str : %s\n", str);
// 	printf("av : str2 : %s\n", str2);

// 	ft_memmove(str2, str, 8);

// 	printf("ap : str : %s\n", str);
// 	printf("ap : str2 : %s\n", str2);

// 	return (0);
// }
