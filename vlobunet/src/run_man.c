/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:22:03 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:22:04 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_man(int i)
{
	ft_putstr(C_ERROR);
	i > 1 ? ft_putendl("man: invalid number of attributes.") : 0;
	i < 1 ? ft_putendl("man : invalid number of attributes.") : 0;
	ft_putstr(C_RESET);
}

int		man_setenv(void)
{
	ft_putstr("\n");
	ft_putendl("  \033[0;30;42m [man setenv] \033[0m");
	ft_putstr("\n");
	ft_putendl("  change or add an environment variable");
	ft_putendl("  setenv [NAME] [VALUE]");
	ft_putstr("\n");
	return (1);
}

void	warning_man(char *str)
{
	ft_putstr("there is no manual for the ");
	ft_putstr(str);
	ft_putendl(" command");
}

void	run_man(char *cmd_atr)
{
	char	**atribut;
	int		i;

	i = 0;
	atribut = ft_strsplit(cmd_atr, 32);
	if (!atribut)
		error_man(0);
	else if (atribut[0] && !atribut[1])
	{
		!ft_strcmp(atribut[0], "echo") ? (i = man_echo()) : 0;
		!ft_strcmp(atribut[0], "cd") ? (i = man_cd()) : 0;
		!ft_strcmp(atribut[0], "getenv") ? (i = man_getenv()) : 0;
		!ft_strcmp(atribut[0], "setenv") ? (i = man_setenv()) : 0;
		!ft_strcmp(atribut[0], "unsetenv") ? (i = man_unsetenv()) : 0;
		!ft_strcmp(atribut[0], "cat") ? (i = man_cat()) : 0;
		i == 0 ? warning_man(atribut[0]) : 0;
		ft_freestrarr(atribut);
	}
	else
		error_man(2);
	ft_freestrarr(atribut);
}
