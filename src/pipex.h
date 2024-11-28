/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:48:38 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/28 14:31:37 by edetoh           ###   ########.fr       */
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

void			ft_freetab(char **tab);
int				check_args(int argc, char **argv);
char			*ft_get_cmd_path(char *str);

typedef struct args_execute
{
	char	**argv;
	int		*fd;
	int		fdin;
	int		fdout;
}				t_args_execute;

t_args_execute	ft_create_args(char **argv, int *fd, int fd_in, int fd_out);
void			ft_redirect_fd(t_args_execute args, int mode);
int				check_args(int argc, char **argv);

#endif