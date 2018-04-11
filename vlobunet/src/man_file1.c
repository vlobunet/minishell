/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_file1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:21:20 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:21:21 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	man_echo(void)
{
	ft_putstr("\n");
	ft_putendl("  \033[0;30;42m [man echo] \033[0m");
	ft_putstr("\n");
	ft_putendl("  display a line of text");
	ft_putendl("  echo [-OPTION]... [STRING]... [-OPTION]... [FILE]");
	ft_putstr("\n");
	ft_putendl("	-n		do not output the trailing newline;");
	ft_putendl(" 	>		write to file");
	ft_putendl(" 	>>		write to the end of the file");
	ft_putstr("\n");
	return (1);
}

int	man_cd(void)
{
	ft_putstr("\n");
	ft_putendl("  \033[0;30;42m [man cd] \033[0m");
	ft_putstr("\n");
	ft_putendl("  go to directory");
	ft_putendl("  cd [name] - go to [name] directory");
	ft_putstr("\n");
	ft_putendl("	cd --	go to home directory");
	ft_putendl(" 	cd -	go to the previous directory");
	ft_putstr("\n");
	return (1);
}

int	man_cat(void)
{
	ft_putstr("\n");
	ft_putendl("  \033[0;30;42m [man cat] \033[0m");
	ft_putstr("\n");
	ft_putendl("  concatenate files and print on the standard output");
	ft_putendl("  cat [OPTION]... [FILE]...");
	ft_putstr("\n");
	ft_putendl("	-e  equivalent to -vE");
	ft_putendl(" 	-E  display $ at end of each line");
	ft_putendl(" 	-n  --number (number all output lines)");
	ft_putendl(" 	-b  --number-nonblank (number nonempty \
	output lines, overrides -n)");
	ft_putstr("\n");
	return (1);
}

int	man_unsetenv(void)
{
	ft_putstr("\n");
	ft_putendl("  \033[0;30;42m [man unsetenv] \033[0m");
	ft_putstr("\n");
	ft_putendl("  delete environment variables");
	ft_putendl("  unsetenv [NAME]...");
	ft_putstr("\n");
	ft_putendl("   \033[35mWARNING! You can not delete the environment \
		variables USER and HOME\033[0m");
	ft_putstr("\n");
	return (1);
}

int	man_getenv(void)
{
	ft_putstr("\n");
	ft_putendl("  \033[0;30;42m [man getenv] \033[0m");
	ft_putstr("\n");
	ft_putendl("  get environment variables");
	ft_putendl("  getenv [NAME=VALUE]...");
	ft_putstr("\n");
	return (1);
}
