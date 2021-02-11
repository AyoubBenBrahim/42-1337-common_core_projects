/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:34:24 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:34:27 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	d_edge(t_part *s, t_part *d, t_farm *farm, t_mem *mem)
{
	add_hold(&(s->adj), &(s->ladj), creat_hold(d, mem));
	farm->map[s->idx][d->idx].c = 1;
	farm->map[s->idx][d->idx].f = 0;
	add_hold(&(d->adj), &(d->ladj), creat_hold(s, mem));
	farm->map[d->idx][s->idx].c = 0;
	farm->map[d->idx][s->idx].f = 0;
}

void	double_edge(t_node *n1, t_node *n2, t_farm *farm, t_mem *mem)
{
	if ((n1->l->adj) == NULL)
		d_edge(n1->l, n1->r, farm, mem);
	if ((n2->l->adj) == NULL)
		d_edge(n2->l, n2->r, farm, mem);
	d_edge(n1->r, n2->l, farm, mem);
	d_edge(n2->r, n1->l, farm, mem);
}

int		split_link(char *line, t_mem *mem)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			return (i);
		i++;
	}
	error(mem);
	return (0);
}

t_node	*find_adrr(char *str, t_node *lst, t_mem *mem)
{
	while (lst)
	{
		if (!(strcmp(lst->name, str)))
			return (lst);
		lst = lst->next;
	}
	error(mem);
	return (0);
}
