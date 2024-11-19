/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:51:10 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/01 15:54:24 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
ft_putnbr_fd writes number 'n' to file 'fd'.
Takes 'n' (number to write) and 'fd' (file descriptor).
Uses write() to write the number to the file.
*/

int	ft_putnbr_fd(int n, int fd)
{
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
	{
		count += ft_putnbr_fd(n / 10, fd) + ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		write(fd, &(char){n + '0'}, 1);
		count++;
	}
	return (count);
}
// #include  <string.h>
// #include  <stdio.h>
// #include  <unistd.h>

// int	main(void)
// {
// 	ft_putnbr_fd(2147483647, 1); // Test INT_MAX
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-2147483648, 1); // Test INT_MIN
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(2050454, 1); // Test nombre aléatoire
// 	write(1, "\n", 1);
// 	return (0);
// }
