/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:21:04 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:21:05 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_exit(void)
{
	ft_putendl("terminated  ./minishell");
	exit(0);
}

void	ft_freestrarr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
}

void	signal1(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		ft_print_message();
		signal(SIGINT, signal1);
	}
}

int		main(int argc, char **argv, char **env)
{
	char	*str;
	char	**command;
	int		i;

	argv++;
	if (argc == 1)
	{
		ft_get_env(env);
		while (1)
		{
			i = 0;
			ft_print_message();
			signal(SIGINT, signal1);
			str = ft_scanf(0);
			command = ft_strsplit(str, ';');
			free(str);
			while (command[i])
				ft_get_cmd(command[i++]);
			ft_freestrarr(command);
		}
		ft_freestrarr(g_env);
	}
	return (0);
}
