/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_graph.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:34:36 by ahel-men          #+#    #+#             */
/*   Updated: 2020/10/29 11:49:58 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_list_node	*ft_create_list_node(int dst)
{
	t_list_node		*room;

	room = (t_list_node *)malloc(sizeof(t_list_node));
	room->dst = dst;
	// room->c = 0;
	// room->f = 0;
	room->edge_cap = 1;
// room->real_predecessor = NULL;
	room->next = NULL;
	return (room);
}

t_graph		*ft_create_graph(int nb)
{
	t_graph			*gr;
	int				i;

	gr = (t_graph *)malloc(sizeof(t_graph));
	gr->nb_v = nb;
	gr->tab = (t_lst *)malloc(sizeof(t_lst) * nb);
	i = -1;
	while (++i < nb)
		gr->tab[i].list = NULL;
	return (gr);
}

// src-dest
//start->nodeA
void		ft_create_link(t_graph *gr, int src, int dest)
{
	// t_list_node		*room;
	// t_list_node		*tmp;

	// room = ft_create_list_node(dest);
	// // room->c = 50;
	// if (!gr->tab[src].list)
	// {
	// 	gr->tab[src].list = room;
	// }
	// else
	// {
	// 	tmp = gr->tab[src].list;
	// 	while (tmp->next)
	// 		tmp = tmp->next;
	// 	tmp->next = room;
	// }
	// room = ft_create_list_node(src);
	// // room->c = -50;
	// if (!gr->tab[dest].list)
	// {
	// 	gr->tab[dest].list = room;
	// }
	// else
	// {
	// 	tmp = gr->tab[dest].list;
	// 	while (tmp->next)
	// 		tmp = tmp->next;
	// 	tmp->next = room;
	// }




	t_list_node		*source;
	t_list_node		*sink;
	t_list_node		*tmp;

	source = ft_create_list_node(src);
	sink = ft_create_list_node(dest);
	if (!gr->tab[source->dst].list)
	{
		gr->tab[source->dst].root = source;
		gr->tab[source->dst].list = sink;
	}
	else
	{
		tmp = gr->tab[source->dst].list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = sink;
	}

	if (!gr->tab[sink->dst].list)
	{
		gr->tab[sink->dst].root = sink;
		gr->tab[sink->dst].list = source;
	}
	else
	{
		tmp = gr->tab[sink->dst].list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = source;
	}
}
