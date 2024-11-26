/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:48:38 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/26 15:34:48 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "../42_libft-mylibft/libft.h"

int		check_args(int argc, char **argv);
void	ft_freetab(char **tab);

typedef struct args_execute
{
	char	**argv;
	int		*fd;
	int		fdin;
	int		fdout;
}				t_args_execute;


#endif