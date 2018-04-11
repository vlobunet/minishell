/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_src.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:25:01 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/11 18:25:02 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo_src1(char **atribut, int fd1, int flag, int n)
{
	int	i;

	i = n + 1 + flag;
	while (atribut[++i])
	{
		ft_putstr_fd(atribut[i], fd1);
		atribut[i + 1] ? ft_putstr_fd(" ", fd1) : 0;
	}
	flag == 0 ? ft_putchar_fd('\n', fd1) : 0;
	close(fd1);
}

void	echo_src2(char **atribut, int fd1, int flag, int n)
{
	int	i;

	i = 0;
	if (atribut[0][0] == '-' && atribut[0][1] == 'n' && !atribut[0][2])
		i++;
	while (i < n)
	{
		ft_putstr_fd(atribut[i], fd1);
		((i + 1) < n) ? ft_putstr_fd(" ", fd1) : 0;
		i++;
	}
	i = i + 1;
	while (atribut[++i])
	{
		ft_putstr_fd(" ", fd1);
		ft_putstr_fd(atribut[i], fd1);
	}
	!flag ? ft_putchar_fd('\n', fd1) : 0;
	close(fd1);
}

void	sintax_error(void)
{
	ft_putstr(C_ERROR);
	ft_putendl("-minishell: syntax error");
	ft_putstr(C_RESET);
}
