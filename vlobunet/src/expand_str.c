/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:19:25 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:19:26 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*set_str(char *src)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	while (src[i])
	{
		while (src[i] && src[i] <= 32)
			i++;
		while (src[i] && src[i++] > 32)
			k++;
	}
	str = ft_strnew(k);
	i = 0;
	k = 0;
	while (src[i])
	{
		while (src[i] && src[i] <= 32)
			i++;
		while (src[i] && src[i] > 32)
			str[k++] = src[i++];
		str[k++] = src[i++];
	}
	return (str);
}
