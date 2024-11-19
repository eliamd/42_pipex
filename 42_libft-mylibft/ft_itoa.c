/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:16:47 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:11:31 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_itoa converts an integer to a string.
 * Takes 'n' (integer). Returns a string representing
 * the integer or NULL on error.
 */

static int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		int_len;
	int		nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	int_len = ft_int_len(n);
	str = malloc((int_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	nb = n;
	str[int_len] = 0;
	if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--int_len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

// #include  <string.h>
// #include  <stdio.h>
// #include  <unistd.h>

// int	main(void)
// {
// 	char *res = ft_itoa(-123456);
// 	printf("===== RESULT iTOA =====\n");
// 	printf("Res : %s\n", res);
// 	printf("=======================\n");
// 	free(res);
// 	return (1);
// }
