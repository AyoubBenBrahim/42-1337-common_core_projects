/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:14:05 by ayb*****          #+#    #+#             */
/*   Updated: 2020/11/07 11:47:02 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*creat_room(char *name, t_mem *mem)
{
	t_room	*room;

	room = ft_malloc(sizeof(t_room), mem);
	room->name = name;
	room->ant = 0;
	room->prev = NULL;
	room->next = NULL;
	return (room);
}

void		add_room(t_room **parc, t_room *room)
{
	(*parc)->prev = room;
	room->next = *parc;
	*parc = room;
}

t_path		*add_path(t_part *part, t_farm *farm, t_mem *mem)
{
	t_path		*p;

	p = ft_malloc(sizeof(t_path), mem);
	p->next = NULL;
	p->prev = NULL;
	p->l = 1;
	p->nb = 0;
	p->parc = creat_room(farm->end->name, mem);
	p->end_ptr = p->parc;
	add_room(&(p->parc), creat_room(part->name, mem));
	part = part->side->prev;
	(p->l)++;
	while (part != farm->start)
	{
		(p->l)++;
		add_room(&(p->parc), creat_room(part->name, mem));
		part = part->side->prev;
	}
	return (p);
}

void		order_path(t_path *p, t_path *path)
{
	while (path)
	{
		if (path->next->l >= p->l)
		{
			p->prev = path;
			p->next = path->next;
			path->next = p;
			path->next->prev = p;
			break ;
		}
		path = path->next;
	}
}

t_path		*creat_path(t_farm *farm, t_mem *mem)
{
	t_hold	*adj;
	t_path	*p[3];

	p[0] = add_path(farm->end->adj->adr, farm, mem);
	p[2] = p[0];
	adj = farm->end->adj;
	while ((adj = adj->next))
	{
		p[1] = add_path(adj->adr, farm, mem);
		if (p[1]->l >= p[2]->l)
		{
			p[2]->next = p[1];
			p[1]->prev = p[2];
			p[2] = p[1];
		}
		else if (p[0]->l >= p[1]->l)
		{
			p[1]->next = p[0];
			p[0]->prev = p[1];
			p[0] = p[1];
		}
		else
			order_path(p[1], p[0]);
	}


		// t_room *room;
		// t_path *p;
		// p = p[0];

		// room = p[0]->end_ptr;
		// while (room)
		// {
		// 	printf("%s|", room->name);
		// 	room = room->prev;
		// }

		// printf("%s|", p[0]->end_ptr->prev->name);
		// printf("\n\n");

	return (p[0]);
}
