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

char	*run_get_env(char *env)
{
	int		i;
	char	*env_join;
	int		size;

	i = -1;
	env_join = ft_strjoin(env, "=");
	size = ft_strlen(env_join);
	while (g_env[++i])
		if (ft_strncmp(g_env[i], env_join, size) == 0)
		{
			free(env_join);
			return (g_env[i]);
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
				env = run_get_env(atr[i]);
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

void	run_env(char *str)
{
	int		i;
	char	**atribut;

	i = 0;
	if (str)
	{
		atribut = ft_strsplit(str, 32);
		if (atribut[0])
		{
			ft_putstr("env: ");
			ft_putstr(atribut[0]);
			ft_putendl(": No such file or directory");
			ft_freestrarr(atribut);
		}
		else
		{
			i = 0;
			while (g_env[i])
				ft_putendl(g_env[i++]);
		}
		ft_freestrarr(atribut);
	}
	else
		while (g_env[i])
			ft_putendl(g_env[i++]);
}
