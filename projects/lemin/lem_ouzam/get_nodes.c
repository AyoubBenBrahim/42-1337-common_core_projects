/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:34:43 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:34:52 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	hash_node(t_mem *mem, t_farm *farm, char *line)
{
	if (cmpstr(line, "##start"))
	{
		if (farm->start)
			error(mem);
		farm->start = get_part(mem, farm);
	}
	else if (cmpstr(line, "##end"))
	{
		if (farm->end)
			error(mem);
		farm->end = get_part(mem, farm);
	}
}

int		get_nodes(t_mem *mem, t_farm *farm)
{
	char	*line;

	while ((line = read_line(mem)))
	{
		if (line[0] == '#')
		{
			if (line[1] == '#')
				hash_node(mem, farm, line);
		}
		else
		{
			if (line[0] == 'L' || line[0] == ' ')
				error(mem);
			if (add_node(line, farm, mem))
				return (1);
		}
	}
	error(mem);
	return (0);
}
