/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:22:48 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:22:49 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	successful_unset(char *str)
{
	ft_putstr(C_YELLO);
	ft_putstr("SUCCESS : ");
	ft_putstr(C_RESET);
	ft_putstr("unsetenv : ");
	ft_putstr(str);
	ft_putendl(" : successfully deleted!");
}

void	run_unset(char *cmd_attr)
{
	int		i;
	int		size;
	char	*str;

	i = -1;
	str = ft_strjoin(cmd_attr, "=");
	size = ft_strlen(str);
	while (g_env[++i])
		if (!ft_strncmp(str, g_env[i], size))
		{
			free(g_env[i]);
			while (g_env[i + 1])
			{
				g_env[i] = ft_strdup(g_env[i + 1]);
				free(g_env[i + 1]);
				i++;
			}
			g_env = realloc_envv(i);
			successful_unset(cmd_attr);
			free(str);
			return ;
		}
	error_unset(cmd_attr);
	free(str);
}

void	run_unsetenv(char *str)
{
	int		i;
	char	**atr;

	i = -1;
	if (str)
	{
		atr = ft_strsplit(str, 32);
		if (atr[0])
		{
			while (atr[++i])
				(ft_strcmp(atr[i], "HOME") && ft_strcmp(atr[i], "USER")) ? \
					run_unset(atr[i]) : error_unset(atr[i]);
			ft_freestrarr(atr);
		}
		else
			ft_putendl("setenv : invalid number of attributes.");
	}
	else
	{
		ft_putstr(C_ERROR);
		ft_putendl("setenv : invalid number of attributes.");
		ft_putstr(C_RESET);
	}
}
