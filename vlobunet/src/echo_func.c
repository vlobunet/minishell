/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:18:50 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:18:51 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_echo(int n, char **atribut)
{
	int fd1;
	int flag;
	int i;

	flag = 0;
	i = 0;
	if (atribut[0][0] == '-' && atribut[0][1] == 'n' && !atribut[0][2])
	{
		flag = 1;
		i++;
	}
	(ft_strcmp(atribut[n], ">") == 0) ? fd1 = open(atribut[n + 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0600) : 0;
	(ft_strcmp(atribut[n], ">>") == 0) ? fd1 = open(atribut[n + 1], \
		O_WRONLY | O_APPEND | O_CREAT, 0600) : 0;
	if (fd1 >= 0 && n == i)
		echo_src2(atribut, fd1, flag, n);
	else if (fd1 >= 0)
		echo_src2(atribut, fd1, flag, n);
	else
		ft_putendl("cat : error O_CREAT");
}

void	file_echo_atr(char **atribut, int n)
{
	int i;

	i = 0;
	if (atribut[0][0] == '-' && atribut[0][1] == 'n' && !atribut[0][2])
		i++;
	(n == i && !atribut[n + 1]) || (n != i && !atribut[n + 1]) \
		? sintax_error() : 0;
	(n == i && atribut[n + 1]) || (n != i && atribut[n + 1]) \
		? print_echo(n, atribut) : 0;
}

void	disp_echo_atr(char **atribut)
{
	int i;
	int flag;

	i = -1;
	flag = 0;
	if (atribut[0] && atribut[0][0] == '-' && \
		atribut[0][1] == 'n' && !atribut[0][2])
	{
		flag = 1;
		i++;
	}
	while (atribut[++i])
	{
		ft_putstr(atribut[i]);
		atribut[i + 1] ? ft_putchar(' ') : 0;
	}
	!flag ? ft_putchar('\n') : 0;
}

int		check_atr_echo(char **atribut)
{
	int i;

	i = -1;
	while (atribut[++i])
		if (!ft_strcmp(atribut[i], ">>") || !ft_strcmp(atribut[i], ">"))
			return (i);
	return (-1);
}

void	run_echo(char *str)
{
	char	**atribut;
	int		n;

	if (str != NULL)
	{
		atribut = ft_split(str);
		n = check_atr_echo(atribut);
		n == -1 ? disp_echo_atr(atribut) : file_echo_atr(atribut, n);
		ft_freestrarr(atribut);
	}
	else
		ft_putchar('\n');
}
