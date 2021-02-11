/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:34:40 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/07 11:46:40 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

long		get_num(char *line, t_mem *mem)
{
	long	i;

	i = 0;
	while (*line)
	{
		i = i * 10 + (*line - '0');
		line++;
	}
	if (i > INT_MAX)
	{
		ft_putstr("MAX_INT = 2147483647\n");
		error(mem);
	}
	return (i);
}

long		get_ants(t_mem *mem)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		if (!(line = read_line(mem)))
			error(mem);
		if (line[0] == '#')
		{
			if (cmpstr(line, "##start") || cmpstr(line, "##end"))
				error(mem);
		}
		else
		{
			while (line[i])
			{
				if (line[i] > '9' || line[i] < '0' || line[i] == '\0')
					error(mem);
				i++;
			}
			break ;
		}
	}
	return (get_num(line, mem));
}
