/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:34:36 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:34:38 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*lpart(char *src, int l, t_mem *mem)
{
	char *part;

	part = ft_malloc(sizeof(char) * (l + 1), mem);
	part[l] = '\0';
	while (l--)
		part[l] = src[l];
	return (part);
}

int		split_node(char *line, int *l, t_mem *mem)
{
	int	i;

	i = 0;
	l[0] = 0;
	while (line[l[0]])
	{
		if (i == 0 && line[l[0]] == '-')
			return (1);
		if (line[l[0]] == ' ')
		{
			if (i < 2)
				l[++i] = l[0];
			else
				error(mem);
		}
		else if (i > 0 && (line[l[0]] > '9' || line[l[0]] < '0'))
			error(mem);
		l[0]++;
	}
	if (i != 2 || l[0] == l[2] + 1)
		error(mem);
	return (0);
}

int		cmpstr(char *str1, char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	return (1);
}
