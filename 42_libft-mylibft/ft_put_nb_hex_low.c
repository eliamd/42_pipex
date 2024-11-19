/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nb_hex_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:03:30 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/28 18:21:11 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexlow(unsigned int num)
{
	char		*hex_digits;
	char		hex[8];
	int			i;
	int			count;

	hex_digits = "0123456789abcdef";
	i = 7;
	while (i >= 0)
	{
		hex[i] = hex_digits[num % 16];
		num /= 16;
		i--;
	}
	count = 0;
	i = 0;
	while (i < 8 && hex[i] == '0')
		i++;
	if (i == 8)
		i = 7;
	while (i < 8)
	{
		count += ft_putchar_fd(hex[i], 1);
		i++;
	}
	return (count);
}
