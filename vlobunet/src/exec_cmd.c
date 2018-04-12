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

void	ch_cmd(char *name, char *str_atr, char *path)
{
	pid_t	p;
	char	**argc;
	char	*tmp;
	char	*src;
	int		status;

	tmp = (str_atr ? ft_strjoin(name, str_atr) : ft_strdup(name));
	argc = ft_strsplit(tmp, 32);
	free(tmp);
	tmp = ft_strjoin(path, "/");
	src = ft_strjoin(tmp, name);
	if (access(src, 0 | 1) == 0)
	{
		p = fork();
		signal(SIGINT, cmd_signal);
		if (p < 0)
			ft_putendl("Fork failed to create a new process.");
		else if (p == 0)
			execve(src, argc, g_env);
		else
			waitpid(p, &status, 0);
	}
	ft_freestrarr(argc);
	free(tmp);
	free(src);
}

void	exec_cmd(char *name, char *str_atr)
{
	char	**path;
	int		i;

	i = -1;
	path = ft_strsplit(ft_strchr(run_get_env("PATH", g_env), '/'), ':');
	while (path[++i])
		ch_cmd(name, str_atr, path[i]);
	(path != NULL) ? ft_freestrarr(path) : 0;
}
