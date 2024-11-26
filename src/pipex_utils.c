/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:20:05 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/26 16:24:54 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

char	*ft_get_cmd_path(char *str)
{
	char	*path;

	path = ft_strjoin("/usr/bin/", str);
	if (!path)
		return (NULL);
	return (path);
}

t_args_execute	ft_create_args(char **argv, int *fd, int fd_in, int fd_out)
{
	t_args_execute	args;

	args.argv = argv;
	args.fd = fd;
	args.fdin = fd_in;
	args.fdout = fd_out;
	return (args);
}

void	ft_redirect_fd(t_args_execute args, int mode)
{
	if (mode == 1)
	{
		dup2(args.fdin, STDIN_FILENO);
		dup2(args.fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(args.fd[0], STDIN_FILENO);
		dup2(args.fdout, STDOUT_FILENO);
	}
	close(args.fd[0]);
	close(args.fd[1]);
}

int	check_args(int argc, char **argv)
{
	int		index;
	char	*cmd_dir;
	char	**arg_tab;

	index = 2;
	if (argc != 5 || !argv[1] || access(argv[1], F_OK) == -1)
		return (0);
	while (argv[index] && index < argc - 1)
	{
		arg_tab = ft_split(argv[index], ' ');
		cmd_dir = ft_strjoin("/usr/bin/", arg_tab[0]);
		if (!cmd_dir)
			return (0);
		if (access(cmd_dir, F_OK) == -1)
			return (ft_freetab(arg_tab), free(arg_tab), free(cmd_dir), 0);
		else
			index++;
		ft_freetab(arg_tab);
		free(arg_tab);
		free(cmd_dir);
	}
	return (1);
}
