/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:30:53 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/28 14:32:01 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*concat_path(const char *dir, const char *cmd)
{
	char	*dir_unslashed;
	char	*full_path;

	dir_unslashed = ft_strjoin(dir, "/");
	if (!dir_unslashed)
		return (NULL);
	full_path = ft_strjoin(dir_unslashed, cmd);
	free(dir_unslashed);
	return (full_path);
}

int	ft_command_found_and_access(char **arg_tab)
{
	char	*cmd_dir;
	char	**pathcmd;
	int		i;

	i = 0;
	pathcmd = ft_split(getenv("PATH"), ':');
	if (!pathcmd)
		return (0);
	while (pathcmd[i])
	{
		cmd_dir = concat_path(pathcmd[i], arg_tab[0]);
		if (!cmd_dir)
			return (ft_freetab(pathcmd), 0);
		if (access(cmd_dir, F_OK) != -1)
			return (free(cmd_dir), ft_freetab(pathcmd), free(pathcmd), 1);
		free(cmd_dir);
		i++;
	}
	return (ft_freetab(pathcmd), 0);
}

int	check_args(int argc, char **argv)
{
	int		index;
	char	**arg_tab;

	index = 2;
	if (argc != 5 || !argv[1] || access(argv[1], F_OK) == -1)
		return (0);
	while (argv[index] && index < argc - 1)
	{
		arg_tab = ft_split(argv[index], ' ');
		if (!arg_tab)
			return (0);
		if (!ft_command_found_and_access(arg_tab))
			return (ft_freetab(arg_tab), free(arg_tab), 0);
		else
			index++;
		ft_freetab(arg_tab);
		free(arg_tab);
	}
	return (1);
}