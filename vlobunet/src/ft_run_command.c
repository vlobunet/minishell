/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:19:47 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:19:48 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#include <stdio.h>

void	ft_run_cmd(char *cmd_name, char *cmd_attr)
{
	char	buf[4098];

	!ft_strcmp(cmd_name, "exit") ? run_exit() : 0;
	!ft_strcmp(cmd_name, "echo") ? run_echo(cmd_attr) : 0;
	!ft_strcmp(cmd_name, "cd") ? run_cd(cmd_attr) : 0;
	!ft_strcmp(cmd_name, "env") ? run_env(cmd_attr) : 0;
	!ft_strcmp(cmd_name, "getenv") ? run_getenv(cmd_attr) : 0;
	!ft_strcmp(cmd_name, "setenv") ? run_setenv(cmd_attr) : 0;
	!ft_strcmp(cmd_name, "unsetenv") ? run_unsetenv(cmd_attr) : 0;
	!ft_strcmp(cmd_name, "cat") ? run_cat(cmd_attr) : 0;
	!ft_strcmp(cmd_name, "pwd") ? ft_putendl(getcwd(buf, 4098)) : 0;
	!ft_strcmp(cmd_name, "clear") ? ft_putstr("\033[0d\033[2J") : 0;
	!ft_strcmp(cmd_name, "man") ? run_man(cmd_attr) : 0;
	!ft_strcmp(cmd_name, "info") ? run_info() : 0;
}

void	command_check(char *name, char *str_atr)
{
	int	i;

	i = 0;
	if ((!ft_strcmp(name, "setenv")) || (!ft_strcmp(name, "cat")) ||\
		(!ft_strcmp(name, "unsetenv")) || (!ft_strcmp(name, "env")) ||\
		(!ft_strcmp(name, "cd")) || (!ft_strcmp(name, "echo")) ||\
		(!ft_strcmp(name, "getenv")) || (!ft_strcmp(name, "pwd")) ||\
		(!ft_strcmp(name, "info")) || (!ft_strcmp(name, "clear")) || \
		(!ft_strcmp(name, "man")) || (!ft_strcmp(name, "info")) || \
		(!ft_strcmp(name, "exit")))
		ft_run_cmd(name, str_atr);
	else
		{
			while (name[i] && name[i] <= 32)
				i++;
			name[i] != 0 ? exec_cmd(name, str_atr) : 0;
		}
}

void	ft_get_cmd(char *cmd)
{
	int		i;
	char	*name = NULL;
	char	*atribut = NULL;
	int		k;

	i = 0;
	while (cmd[i] && cmd[i] <= 32)
		i++;
	k = i;
	while (cmd[k] > 32)
		k++;
	name = ft_strndup(cmd + i, k - i);
	while (cmd[k] && cmd[k] <= 32)
		k++;
	if (cmd[k])
		atribut = ft_strdup(cmd + i + k);
	command_check(name, atribut);
	name ? free(name) : 0;
	atribut != NULL ? free(atribut) : 0;
}
