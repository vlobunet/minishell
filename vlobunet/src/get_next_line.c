/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:20:35 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:20:36 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	char	*ft_my_join(size_t size, char *line)
{
	char	*newline;
	int		i;

	if (!line)
		return (ft_strnew(size));
	i = ft_strlen(line);
	newline = ft_strnew(size + i);
	ft_strcpy(newline, line);
	ft_strdel(&line);
	return (newline);
}

static	char	*ft_chrline(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		return ((char *)&s[i]);
	else
		return (NULL);
}

static	int		ft_cheackbuff(char *str, char **line)
{
	char	*src;
	int		col[2];

	if ((src = ft_chrline(str)))
	{
		col[1] = src - str;
		*line = ft_my_join(col[1], *line);
		ft_strncat(*line, str, col[1]);
		ft_memmove(str, src + 1, ft_strlen(src));
		return (1);
	}
	if ((col[0] = ft_strlen(str)))
	{
		*line = ft_my_join(col[0], *line);
		ft_strncat(*line, str, col[0]);
		*str = 0;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*lst;
	int			coll;

	if (fd < 0 || !line)
		return (-1);
	if (!lst)
		lst = ft_strnew(BUFF_SIZE);
	*line = NULL;
	if (ft_cheackbuff(lst, line))
		return (1);
	while ((coll = read(fd, lst, BUFF_SIZE)) > 0)
	{
		lst[coll] = '\0';
		if (ft_cheackbuff(lst, line) == 1)
			return (1);
	}
	if (*line)
		return (1);
	ft_strdel(&lst);
	if (coll < 0)
		return (-1);
	return (0);
}
