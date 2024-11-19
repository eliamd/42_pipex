/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:01:43 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/04 17:28:08 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert_to_hex(uintptr_t addr, char *address)
{
	char	*hex_digits;
	int		i;

	i = 15;
	hex_digits = "0123456789abcdef";
	address[16] = '\0';
	while (i >= 0)
	{
		address[i] = hex_digits[addr % 16];
		addr /= 16;
		i--;
	}
}

int	ft_putadress(void *ptr)
{
	uintptr_t	addr;
	char		address[17];
	int			start;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	addr = (uintptr_t)ptr;
	convert_to_hex(addr, address);
	if (write(1, "0x", 2) < 1)
		return (-1);
	start = 0;
	while (start < 16 && address[start] == '0')
		start++;
	if (start == 16)
		start = 15;
	write(1, &address[start], 16 - start);
	return (2 + 16 - start);
}
