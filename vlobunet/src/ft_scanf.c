/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:20:05 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:20:06 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_resize(char buff, char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	if (s1)
	{
		dup = ft_strnew(ft_strlen(s1) + 1);
		while (s1[i] != '\0')
		{
			dup[i] = s1[i];
			i++;
		}
		dup[i] = buff;
		dup[i + 1] = '\0';
		free(s1);
		return (dup);
	}
	return (NULL);
}

char	*ft_scanf(int fd)
{
	char	buff;
	char	*command;

	command = ft_strnew(0);
	while ((read(fd, &buff, 1)) && buff != '\n')
		command = ft_resize(buff, command);
	return (command);
}
