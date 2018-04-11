/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:18:01 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:18:03 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cat_from_file(char **atr, int flag, t_param *lst_pr)
{
	int	n[3];

	n[1] = 0;
	n[0] = 1;
	n[2] = 0;
	if (flag == 0)
		while (atr[n[1]])
			n[0] = print_file_fd(lst_pr, atr[n[1]++], n[0], n[2]);
	else if (flag == 5)
	{
		while (ft_strcmp(atr[n[1]], ">") && ft_strcmp(atr[n[1]], ">>"))
			n[1]++;
		(ft_strcmp(atr[n[1]], ">") == 0) ? n[2] = open(atr[n[1] + 1], \
			O_WRONLY | O_CREAT | O_TRUNC, 0600) : 0;
		(ft_strcmp(atr[n[1]], ">>") == 0) ? n[2] = open(atr[n[1] + 1], \
			O_WRONLY | O_APPEND | O_CREAT, 0600) : 0;
		(n[2] == -1) ? ft_putstr("cat: error opening the file!") : 0;
		if (n[2] >= 0)
		{
			n[1] = 0;
			while (ft_strcmp(atr[n[1]], ">") && ft_strcmp(atr[n[1]], ">>"))\
				n[0] = print_file_fd(lst_pr, atr[n[1]++], n[0], n[2]);
			close(n[2]);
		}
	}
}

int		cheack_sq(char **atribut)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (atribut[++i])
		if (ft_strcmp(atribut[i], ">>") == 0 || ft_strcmp(atribut[i], ">") == 0)
		{
			flag = 1;
			break ;
		}
	if (flag && i != 0 && !atribut[i + 1])
		return (1);
	else if (flag && !i && !atribut[i + 1])
		return (2);
	else if (flag && !i && atribut[i + 1] && !atribut[i + 2])
		return (3);
	else if (flag && !i && atribut[i + 1])
		return (4);
	else if (flag && i && atribut[i + 1] && !atribut[i + 2])
		return (5);
	else if (flag && i && atribut[i + 1])
		return (6);
	return (0);
}

void	cat_from_keyboard(char **cmd_attr, int flag, t_param *lst_pr)
{
	char	buff;
	char	*command;
	int		n[3];

	n[2] = 1;
	n[0] = 1;
	n[1] = 0;
	command = ft_strnew(0);
	while (read(n[2], &buff, 1))
		command = ft_resize(buff, command);
	flag == 2 ? n[0] = print_str_fd(command, n[2], lst_pr, n[0]) : 0;
	if (flag == 3)
	{
		while (ft_strcmp(cmd_attr[n[1]], ">") && \
			ft_strcmp(cmd_attr[n[1]], ">>"))
			n[1]++;
		(ft_strcmp(cmd_attr[n[1]], ">") == 0) ? n[2] = open(cmd_attr[n[1] \
			+ 1], O_WRONLY | O_CREAT | O_TRUNC, 0600) : 0;
		(ft_strcmp(cmd_attr[n[1]], ">>") == 0) ? n[2] = open(cmd_attr[n[1]\
			+ 1], O_WRONLY | O_APPEND | O_CREAT, 0600) : 0;
		(n[2] == -1) ? ft_putstr("cat: error opening the file!") : 0;
		n[2] != -1 ? n[0] = print_str_fd(command, n[2], lst_pr, n[0]) : 0;
		close(n[2]);
	}
	free(command);
}

void	ft_get_param(char **cmd_attr, t_param *lst_pr)
{
	int	i;
	int	flag;

	i = 0;
	while (cmd_attr[i] && cmd_attr[i][0] == '-')
	{
		if (ft_pars_param(cmd_attr[i], lst_pr) == 0)
			i++;
		else
			return ;
	}
	flag = cheack_sq(cmd_attr + i);
	(flag == 1 || flag == 4) ? error_cat_1(flag, cmd_attr + 1) : 0;
	(flag == 2 || flag == 3) ? cat_from_keyboard(cmd_attr + i,\
		flag, lst_pr) : 0;
	(flag == 5 || flag == 0 || flag == 6) ? \
		cat_from_file(cmd_attr + i, flag, lst_pr) : 0;
}

void	run_cat(char *cmd_attr)
{
	t_param	lst_pr;
	char	**atribut;

	lst_pr = (t_param){0, 0, 0, 0};
	if (cmd_attr)
	{
		atribut = ft_strsplit(cmd_attr, ' ');
		ft_get_param(atribut, &lst_pr);
		ft_freestrarr(atribut);
	}
}
