/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:37:34 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:37:36 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		link_end(char *s, t_farm *farm, t_mem *mem)
{
	t_node	*n;

	if (cmpstr(s, farm->start->name))
		return (1);
	n = find_adrr(s, farm->node, mem);
	if (n->l->adj == NULL)
		d_edge(n->l, n->r, farm, mem);
	add_hold(&(n->r->adj), &(n->r->ladj), creat_hold(farm->end, mem));
	farm->map[n->r->idx][farm->end->idx].f = 0;
	farm->map[n->r->idx][farm->end->idx].c = -1;
	return (0);
}

int		link_start(char *s, t_farm *farm, t_mem *mem)
{
	t_node *n;

	if (cmpstr(s, farm->end->name))
		return (1);
	n = find_adrr(s, farm->node, mem);
	if (!(n->l->adj))
		d_edge(n->l, n->r, farm, mem);
	add_hold(&(farm->start->adj), &(farm->start->ladj), creat_hold(n->l, mem));
	farm->map[farm->start->idx][n->l->idx].f = 0;
	farm->map[farm->start->idx][n->l->idx].c = 1;
	return (0);
}

int		link_node(char *s1, char *s2, t_farm *farm, t_mem *mem)
{
	t_node	*nodes[2];
	t_node	*node;

	nodes[0] = NULL;
	nodes[1] = NULL;
	node = farm->node;
	while (node && (!(nodes[0]) || !(nodes[1])))
	{
		if (!(nodes[0]) && cmpstr(node->name, s1))
			nodes[0] = node;
		if (!(nodes[1]) && cmpstr(node->name, s2))
			nodes[1] = node;
		node = node->next;
	}
	if (nodes[1] && nodes[0])
	{
		double_edge(nodes[0], nodes[1], farm, mem);
		return (1);
	}
	error(mem);
	return (0);
}

int		ft_link(char *line, t_farm *farm, t_mem *mem)
{
	int l;
	int i;

	l = 0;
	i = split_link(line, mem);
	line[i] = '\0';
	if (cmpstr(line, farm->start->name))
		l = link_start(line + i + 1, farm, mem);
	else if (cmpstr(line + i + 1, farm->start->name))
		l = link_start(line, farm, mem);
	else if (cmpstr(line, farm->end->name))
		l = link_end(line + i + 1, farm, mem);
	else if (cmpstr(line + i + 1, farm->end->name))
		l = link_end(line, farm, mem);
	else
		link_node(line, line + i + 1, farm, mem);
	line[i] = '-';
	if (l)
		start_to_end(farm, mem);
	return (l);
}

int		get_links(t_mem *mem, t_farm *farm)
{
	char *line;
	char c;

	line = mem->lline->adr;
	while (1)
	{
		if (line[0] != '#')
			ft_link(line, farm, mem);
		else
		{
			if (cmpstr(line, "##start"))
				error(mem);
			if (cmpstr(line, "##end"))
				error(mem);
		}
		if (!(line = read_line(mem)))
		{
			if ((read(0, &c, 1)))
				error(mem);
			else
				break ;
		}
	}
	return (0);
}
