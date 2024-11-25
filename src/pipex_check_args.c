/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_check_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:49:35 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/25 15:17:19 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}

}

int check_args(int argc, char **argv)
{
	int 	index;
	char 	*cmd_dir;
	char	**arg_tab;

	index = 2;
	if (argc != 5 || !argv[1] || access(argv[1], F_OK) == -1)
		return (0);

	while (argv[index] && index < argc - 1)
	{
		arg_tab = ft_split(argv[index], ' ');
		cmd_dir = ft_strjoin("/usr/bin/", arg_tab[0]);
		if(!cmd_dir)
			return (0);
		if (access(cmd_dir, F_OK) == -1)
			return(ft_freetab(arg_tab), free(arg_tab), free(cmd_dir), 0);
		else
			index++;
		ft_freetab(arg_tab);
		free(arg_tab);
		free(cmd_dir);
	}
	return (1);
}
