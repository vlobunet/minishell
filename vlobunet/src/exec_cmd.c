/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:16:50 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/11 18:16:51 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_signal(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, cmd_signal);
	}
}

char	**get_argv(char *name, char *str_atr)
{
	char	*tmp;
	char	**atr;
	char	*src;

	if (str_atr)
	{
		src = ft_strjoin(name, " ");
		tmp = ft_strjoin(src, str_atr);
		free(src);
	}
	else
		tmp = ft_strdup(name);
	atr = ft_strsplit(tmp, 32);
	free(tmp);
	return (atr);
}

int		ch_cmd(char *name, char *str_atr, char *path)
{
	pid_t	p;
	char	**argv;
	char	*tmp;
	char	*src;
	int		status;

	status = -1;
	argv = get_argv(name, str_atr);
	tmp = ft_strjoin(path, "/");
	src = ft_strjoin(tmp, name);
	free(tmp);
	if (access(src, 0 | 1) == 0)
	{
		p = fork();
		signal(SIGINT, cmd_signal);
		if (p < 0)
			ft_putendl("Fork failed to create a new process.");
		else if (p == 0)
			execve(src, argv, g_env);
		else
			waitpid(p, &status, 0);
	}
	ft_freestrarr(argv);
	free(src);
	return (status);
}

void	exec_cmd(char *str, char *str_atr)
{
	char	**path;
	char	*name;
	int		flag;
	int		i;

	i = -1;
	flag = 0;
	if (str[0] == '/')
	{
		name = pars_name_cmd(str);
		path = ft_strsplit(name, ':');
		free(name);
		name = ft_strdup(str + ft_strlen(path[0]) + 1);
		free(str);
		str = ft_strdup(name);
		free(name);
	}
	else
		path = ft_strsplit(ft_strchr(run_get_env("PATH", g_env), '/'), ':');
	while (path[++i])
		ch_cmd(str, str_atr, path[i]) == 0 ? flag = 1 : 0;
	(path != NULL) ? ft_freestrarr(path) : 0;
	if (!flag)
		ft_putendl("No access or command not found");
}
