/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:45:00 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/18 14:05:45 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_format(char format, va_list *ap)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(*ap, int), 1));
	else if (format == 's')
		return (ft_putstr_fd(va_arg(*ap, char *), 1));
	else if (format == 'p')
		return (ft_putadress(va_arg(*ap, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(*ap, int), 1));
	else if (format == 'u')
		return (ft_put_unsigned_nbr_fd(va_arg(*ap, int), 1));
	else if (format == 'x')
		return (ft_puthexlow(va_arg(*ap, unsigned int)));
	else if (format == 'X')
		return (ft_puthexup(va_arg(*ap, unsigned int)));
	else
		return (write(1, &format, 1));
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			count;

	count = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str != '\0')
			{
				count += print_format(*str, &ap);
			}
		}
		else
		{
			if (write(1, str, 1) < 1)
				return (-1);
			count ++;
		}
		str++;
	}
	va_end(ap);
	return (count);
}
