/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:22:22 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:22:22 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**realloc_envv(int size)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	i = -1;
	while (g_env[++i] && i < size)
	{
		new[i] = ft_strdup(g_env[i]);
		free(g_env[i]);
	}
	free(g_env);
	return (new);
}

void	run_set(char *cmd_attr0, char *cmd_attr1)
{
	int		i;
	int		size;
	char	*atribut;

	i = -1;
	atribut = ft_strjoin(cmd_attr0, "=");
	size = ft_strlen(atribut);
	while (g_env[++i])
		if (!ft_strncmp(atribut, g_env[i], size))
		{
			free(g_env[i]);
			g_env[i] = ft_strjoin(atribut, cmd_attr1);
			free(atribut);
			return ;
		}
	g_env = realloc_envv(i + 1);
	g_env[i++] = ft_strjoin(atribut, cmd_attr1);
	free(atribut);
	g_env[i] = 0;
}

void	run_setenv(char *str)
{
	int		i;
	char	**atribut;

	i = 1;
	if (str)
	{
		atribut = ft_strsplit(str, 32);
		while (atribut[i])
			i++;
		i == 2 ? run_set(atribut[0], atribut[1]) : error_setenv(i);
		ft_freestrarr(atribut);
	}
	else
		error_setenv(0);
}
