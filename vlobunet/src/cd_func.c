/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:18:26 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:18:33 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	change_dir(char *path)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
		run_set("OLDPWD", cwd);
	else
	{
		ft_putstr("cd: ");
		if (access(path, F_OK) == -1)
			ft_putstr("no such file or directory: ");
		else if (access(path, R_OK) == -1)
			ft_putstr("permission denied: ");
		else
			ft_putstr("not a directory: ");
		ft_putendl(path);
	}
}

void	run_cd(char *cmd)
{
	char	*home;
	char	**args;
	char	*thom;

	args = NULL;
	thom = NULL;
	home = ft_get_env_var("HOME=");
	args = ft_strsplit(cmd, 32);
	if (args == NULL)
		change_dir(home);
	else if (args[0] && args[1])
		ft_putendl("cd: too many arguments");
	else
	{
		if (ft_strequ(args[0], "--"))
			change_dir(home);
		else if (args[0][0] == '-' && !args[0][2])
			change_dir(ft_get_env_var("OLDPWD="));
		else if (args[0][0] == '~')
			change_dir(thom = ft_strjoin(home, args[0] + 1));
		else
			change_dir(args[0]);
	}
	thom != NULL ? free(thom) : 0;
	args != NULL ? ft_freestrarr(args) : 0;
}

int		ft_ch_sumb(char *str, char s)
{
	while (*str)
		if (s == *str++)
			return (1);
	return (0);
}
