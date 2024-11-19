/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:34:23 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/04 13:48:31 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_putchar_fd writes character 'c' to 'fd'.
Takes 'c' (character to be written) and 'fd' (file descriptor).
Uses write() to write the character.
*/

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

// #include  <string.h>
// #include  <stdio.h>
// #include  <unistd.h>

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;
// 	printf("===== RESULT Putchar fd =====\n");
// 	ft_putchar_fd('C', 1);
// 	printf("=============================\n");
// 	return (1);
// }
