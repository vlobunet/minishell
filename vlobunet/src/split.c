/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:22:34 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:22:35 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		count_words(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && *str <= 32)
			str++;
		if (*str && *str == 34)
		{
			str++;
			count++;
			while (*str && *str != 34)
				str++;
			if (*str == 34)
				str++;
		}
		else if (*str)
		{
			count++;
			while (*str && *str > 32)
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] > 32 && str[i] != ';')
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] > 32 && str[i] != ';')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	*malloc_wordr(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i + 1] && str[i + 1] != 34)
		i++;
	word = ft_strnew(i);
	i = 0;
	while (str[i + 1] && str[i + 1] != 34)
	{
		word[i] = str[i + 1];
		i++;
	}
	return (word);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		i;

	tab = (char **)malloc(sizeof(char*) * (count_words(str) + 1));
	i = 0;
	while (*str)
	{
		while (*str && *str <= 32)
			str++;
		if (*str && *str != 34)
		{
			tab[i++] = malloc_word(str);
			while (*str && *str > 32)
				str++;
		}
		else if (*str)
		{
			tab[i++] = malloc_wordr(str++);
			while (*str && *str != 34)
				str++;
			str++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
