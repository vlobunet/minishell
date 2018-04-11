/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:21:35 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:21:36 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_get_env_var(char *str)
{
	int	i;
	int	size;

	i = 0;
	if (!g_env)
		return (NULL);
	size = ft_strlen(str);
	while (g_env[i])
	{
		if (ft_strncmp(str, g_env[i], size) == 0)
			return (g_env[i] + size);
		i++;
	}
	return (NULL);
}

char	*ft_goto(char *cwd, char *homedir)
{
	char	*pwd;

	if (ft_strcmp(cwd, homedir) == 0)
		pwd = ft_strdup(" ~");
	else if (ft_strcmp(cwd, homedir) < 0)
		pwd = ft_strjoin(" ", cwd);
	else
	{
		while (*cwd++ == *homedir++)
			;
		pwd = ft_strjoin(" ~/", cwd);
	}
	return (pwd);
}

void	ft_print_message(void)
{
	char	*str;
	char	buff[4097];
	char	*pwd;

	str = ft_get_env_var("USER=");
	ft_putstr(C_FIOLE);
	ft_putstr(str);
	ft_putchar('@');
	ft_putstr(str);
	str = ft_get_env_var("HOME=");
	pwd = ft_goto(getcwd(buff, 4096), str);
	ft_putstr(C_SINIY);
	ft_putstr(pwd);
	ft_putstr(" $> ");
	ft_putstr(C_RESET);
	free(pwd);
}

void	ft_get_env(char **env)
{
	int	i;

	i = 1;
	if (!env)
		return ;
	while (env[i])
		i++;
	g_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env[++i])
	{
		g_env[i] = ft_strdup(env[i]);
	}
	return ;
}
