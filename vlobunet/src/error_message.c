/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:19:05 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:19:07 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_command(char *name)
{
	ft_putstr(C_ERROR);
	ft_putstr(name);
	ft_putendl(": command not found");
	ft_putstr(C_RESET);
}

void	error_setenv(int i)
{
	ft_putstr(C_ERROR);
	i > 2 ? ft_putendl("setenv : invalid number of attributes") : 0;
	i < 2 ? ft_putendl("setenv : Too few atribut.") : 0;
	ft_putstr(C_RESET);
}

void	error_arg(char arg)
{
	ft_putstr("cat: illegal option -- ");
	ft_putchar(arg);
	ft_putstr("\nusage: ft_ls [-eEnb] [file ...]\n");
}

void	error_file(char *arg)
{
	ft_putstr("cat: ");
	ft_putstr(arg);
	ft_putstr(" : file not found!\n");
}
