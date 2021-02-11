/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:35:53 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:35:55 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_part	*creat_part(char *name, int *idx, t_mem *mem)
{
	t_part	*part;

	part = ft_malloc(sizeof(t_part), mem);
	part->idx = *idx;
	(*idx)++;
	part->name = name;
	part->adj = NULL;
	part->v = 0;
	return (part);
}

void	check_name(char *name, t_farm *farm, t_mem *mem)
{
	t_node *node;

	if (farm->end && cmpstr(farm->end->name, name))
		error(mem);
	if (farm->start && cmpstr(farm->start->name, name))
		error(mem);
	node = farm->node;
	while (node)
	{
		if (cmpstr(farm->node->name, name))
			error(mem);
		node = node->next;
	}
}

t_part	*get_part(t_mem *mem, t_farm *farm)
{
	char	*line;
	int		l[4];
	char	*name;

	if (!(line = read_line(mem)) || line[0] == 'L' || line[0] == ' ')
		error(mem);
	if ((split_node(line, l, mem)))
		error(mem);
	line[l[2]] = '\0';
	if ((l[3] = l[2] - l[1] - 1) > 10
			|| (l[3] == 10 && ft_strcmp(line + l[1], "2147483647") > 0))
		error(mem);
	line[l[2]] = ' ';
	if ((l[3] = l[0] - l[2] - 1) > 10
			|| (l[3] == 10 && ft_strcmp(line + l[2], "2147483647") > 0))
		error(mem);
	name = lpart(line, l[1], mem);
	check_name(name, farm, mem);
	return (creat_part(name, &(farm->size), mem));
}
