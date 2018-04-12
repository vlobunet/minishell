/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:23:13 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/11 18:23:14 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_cat_1(int n, char **atribut)
{
	int	fd;
	int	i;

	i = 0;
	ft_putstr(C_ERROR);
	n == 1 ? sintax_error() : 0;
	if (n == 4)
	{
		while (atribut[i] && ft_strcmp(atribut[i], ">>") && \
			ft_strcmp(atribut[i], ">"))
		{
			fd = open(atribut[i], O_RDONLY);
			fd < 0 ? error_file(atribut[i]) : close(fd);
			i++;
		}
		i++;
		fd = open(atribut[i], O_WRONLY | O_CREAT | O_TRUNC, 0600);
		fd < 0 ? ft_putendl("cat : error O_CREAT") : close(fd);
		while (atribut[++i])
		{
			fd = open(atribut[i], O_RDONLY);
			fd < 0 ? error_file(atribut[i]) : close(fd);
		}
	}
	ft_putstr(C_RESET);
}

int		print_str_fd(char *str, int fd, t_param *lst_pr, int i)
{
	int		n;
	char	**cmd;

	n = -1;
	cmd = ft_strsplit(str, '\n');
	ft_putchar('\n');
	while (cmd[++n])
	{
		if (lst_pr->b && ft_strlen(cmd[n]) > 0)
			ft_putnbr_fd(i++, fd);
		else if (lst_pr->n)
			ft_putnbr_fd(i++, fd);
		lst_pr->b || lst_pr->n ? ft_putchar_fd(' ', fd) : 0;
		ft_putstr_fd(cmd[n], fd);
		lst_pr->e == 1 ? ft_putstr_fd("$\n", fd) : ft_putchar_fd('\n', fd);
	}
	ft_freestrarr(cmd);
	return (i);
}

int		print_file_fd(t_param *lst_pr, char *f_name, int i, int fd)
{
	int		fdf;
	char	*line;

	if ((fdf = open(f_name, O_RDONLY)) >= 0)
	{
		while (get_next_line(fdf, &line))
		{
			if (lst_pr->b && ft_strlen(line) > 0)
				ft_putnbr_fd(i++, fd);
			else if (lst_pr->n)
				ft_putnbr_fd(i++, fd);
			lst_pr->b || lst_pr->n ? ft_putchar_fd(' ', fd) : 0;
			ft_putstr_fd(line, fd);
			lst_pr->e == 1 ? ft_putstr_fd("$\n", fd) : ft_putchar_fd('\n', fd);
			free(line);
		}
		close(fdf);
	}
	else
		error_file(f_name);
	return (i);
}

int		cheack_file_name(char *cmd_attr)
{
	int	fd;

	if (*cmd_attr)
	{
		fd = open(cmd_attr, O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			return (1);
		}
	}
	error_file(cmd_attr);
	return (0);
}

int		ft_pars_param(char *cmd_attr, t_param *lst_pr)
{
	int	i;

	i = 1;
	while (cmd_attr[i])
	{
		if (ft_ch_sumb("eEnbiu", cmd_attr[i]))
		{
			lst_pr->e = (cmd_attr[i] == 'e' ? 1 : lst_pr->e);
			lst_pr->e = (cmd_attr[i] == 'E' ? 1 : lst_pr->e);
			lst_pr->n = (cmd_attr[i] == 'n' ? 1 : lst_pr->n);
			lst_pr->b = (cmd_attr[i] == 'b' ? 1 : lst_pr->b);
			lst_pr->i = (cmd_attr[i] == 'i' ? 1 : lst_pr->n);
			lst_pr->u = (cmd_attr[i] == 'u' ? 1 : lst_pr->b);
		}
		else
		{
			error_arg(cmd_attr[i]);
			return (-1);
		}
		i++;
	}
	return (0);
}
