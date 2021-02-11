/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:28:57 by ouzamhar          #+#    #+#             */
/*   Updated: 2020/11/04 23:47:02 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*creat_node(char *name, int *idx, t_mem *mem)
{
	t_node *node;

	node = ft_malloc(sizeof(t_node), mem);
	node->name = name;
	node->next = NULL;
	node->l = creat_part(node->name, idx, mem);
	node->r = creat_part(node->name, idx, mem);
	node->r->side = node->l;
	return (node);
}

void	check_node(char *name, t_farm *farm, t_mem *mem)
{
	t_node *node;

	node = farm->node;
	while (node && node->next)
	{
		if (cmpstr(node->name, name))
			error(mem);
		node = node->next;
	}
	if (cmpstr(node->name, name))
		error(mem);
	node->next = creat_node(name, &(farm->size), mem);
}

int		add_node(char *line, t_farm *farm, t_mem *mem)
{
	int		l[3];
	char	*name;
	int		f;

	if (split_node(line, l, mem))
		return (1);
	f = l[2] - l[1] - 1;
	if (f > 10 || (f == 10 && ft_strcmp(line + l[1], "2147483647") > 0))
		error(mem);
	f = l[0] - l[2] - 1;
	if (f > 10 || (f == 10 && ft_strcmp(line + l[2], "2147483647") > 0))
		error(mem);
	name = lpart(line, l[1], mem);
	if (farm->end && cmpstr(farm->end->name, name))
		error(mem);
	if (farm->start && cmpstr(farm->start->name, name))
		error(mem);
	if (farm->node)
		check_node(name, farm, mem);
	else
		farm->node = creat_node(name, &(farm->size), mem);
	return (0);
}
