/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:20:50 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:20:51 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*run_get_env(char *env, char **env_g)
{
	int		i;
	char	*env_join;
	int		size;

	i = -1;
	env_join = ft_strjoin(env, "=");
	size = ft_strlen(env_join);
	while (env_g[++i])
		if (ft_strncmp(env_g[i], env_join, size) == 0)
		{
			free(env_join);
			return (env_g[i]);
		}
	ft_putstr(C_ERROR);
	ft_putstr("getenv: Wrong atribut: ");
	ft_putendl(env);
	ft_putstr(C_RESET);
	free(env_join);
	return (NULL);
}

void	run_getenv(char *atribut)
{
	char	**atr;
	int		i;
	char	*env;

	i = -1;
	if (atribut)
	{
		atr = ft_strsplit(atribut, 32);
		if (atr[0])
		{
			while (atr[++i])
			{
				env = run_get_env(atr[i], g_env);
				if (env != NULL)
					ft_putendl(env);
			}
			ft_freestrarr(atr);
			return ;
		}
		ft_freestrarr(atr);
	} 
	ft_putstr(C_ERROR);
	ft_putendl("getenv: invalid number of attributes");
	ft_putstr(C_RESET);
}

char	**ft_env_dup(char *tmp)
{
	int		i;
	char	**env;
	int		size;
	int		flag;
	int		j;


	i = -1;
	j = 0;
	flag = 0;
	if (!g_env || !tmp)
		return (NULL);
	size = ft_strlen(tmp);
	while (g_env[++i])
		!ft_strncmp(tmp, g_env[i], size) ? flag = 1 : 0;
	flag == 1 ? i-- : 0;
	env = (char **)malloc(sizeof(char *) * (i + 1));
	env[i + 1] = NULL;
	i = -1;
	while (g_env[++i])
		ft_strncmp(tmp, g_env[i], size) ? env[j++] = ft_strdup(g_env[i]) : 0;
	env[j] = 0;
	return (env);
}

char	*pars_name_cmd(char *cmd)
{
	int		i;
	int		x;
	char	*path;

	i = -1;
	while (cmd[++i])
		(cmd[i] == '/') ? x = i : 0;
	path = ft_strnew(x);
	i = -1;
	while (++i != x)
		path[i] = cmd[i];
	return(path);
}

int	env_exec_cmd(char *path, char *name, char **env, char **argv)
{
	pid_t	p;
	char	*tmp;
	char	*src;
	int		status;

	status = -1;
	tmp = ft_strjoin(path, "/");
	src = ft_strjoin(tmp, name);
	if (access(src, 0 | 1) == 0)
	{
		p = fork();
		signal(SIGINT, cmd_signal);
		if (p < 0)
			ft_putendl("Fork failed to create a new process.");
		else if (p == 0)
			execve(src, argv, env);
		else
			waitpid(p, &status, 0);
	}
	free(tmp);
	free(src);
	return(status);
}

void	env_exec(char **atr, char **env)
{
	int	i;
	char **path;
	char *name;
	int flag;

	flag = 0;
	if (atr[0][0] == '/')
	{
		name = pars_name_cmd(atr[0]);
		path = ft_strsplit(name, ':');
		free(name);
		name = ft_strdup(atr[0] + ft_strlen(path[0]) + 1);
		free(atr[0]);
		atr[0] = ft_strdup(name);
		free(name);
	}
	else
		path = ft_strsplit(ft_strchr(run_get_env("PATH", env), '/'), ':');
	i = -1;
	while (path[++i])
		env_exec_cmd(path[i], atr[0], env, atr) == 0 ? flag = 1 : 0;
	ft_freestrarr(path);
	if (!flag)
		ft_putendl("No access or file not found");
}

char	**ft_env_dupx(void)
{
	char	**env;

	env = (char **)malloc(sizeof(char *) * (4));
	env[0] = ft_strdup(run_get_env("PATH", g_env));
	env[1] = ft_strdup(run_get_env("USER", g_env));
	env[2] = ft_strdup(run_get_env("HOME", g_env));
	env[3] = NULL;
	return (env);

}

void	run_env_ex(char **atr)
{
	t_param	lst_pr;
	int		i;
	char	**env;

	i = -1;
	env = NULL;
	lst_pr = (t_param){0, 0, 0, 0, 0, 0};
	while(atr[++i] && atr[i][0] == '-')
		if (ft_pars_param(atr[i], &lst_pr) == -1)
			return ;
	if (i && lst_pr.i && atr[i] != NULL)
	{
		env = ft_env_dupx();
		env_exec(atr + i, env);
	}
	else if (i && lst_pr.u && atr[i] != NULL)
	{
		env = (ft_strcmp(atr[i], "PATH") ? ft_env_dup(atr[i]) : ft_env_dup("p"));
		env_exec(atr + i + 1, env);
	}
	else if (atr[i] != NULL)
		env_exec(atr + i, g_env);
	else
		run_man("env");
	env != NULL ? ft_freestrarr(env) : 0;
}

void	run_env(char *str)
{
	int		i;
	char	**atr;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] <= 32)
			i++;
		atr = ft_strsplit(str + i, 32);
		run_env_ex(atr);
		ft_freestrarr(atr);
		return ;
	}
	while (g_env[i])
		ft_putendl(g_env[i++]);
}




















