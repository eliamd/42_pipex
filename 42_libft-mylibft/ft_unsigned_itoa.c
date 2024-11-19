/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:52:17 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/28 17:53:01 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_unsigned_int_len(unsigned int n)
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

char	*ft_unsigned_itoa(unsigned int n)
{
	char				*str;
	int					int_len;
	unsigned int		nb;

	int_len = ft_unsigned_int_len(n);
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
