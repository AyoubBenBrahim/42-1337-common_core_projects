/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortestpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:37:47 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:37:48 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		open_surg(t_queue *q, t_surg *surg, t_farm *farm, t_mem *mem)
{
	t_hold	*adj;
	t_part	*p;
	adj = surg->adj;
	p = farm->end;
// printf ("			****** open_surg *****|%s|=\n", ((t_part *)adj->adr)->name);
	while (adj)
	{

		if (((t_part *)adj->adr)->v != q->v)
		{
			if (farm->map[surg->prev->idx][((t_part *)adj->adr)->idx].c == 1)
			{
				enqueue(q, adj->adr, mem);
				((t_part *)adj->adr)->v = q->v;
				// printf("prev = %s\n", surg->prev->name);
				// if (((t_part *)adj->adr)->lprev)
					// printf("old Lprev = %s\n", ((t_part *)adj->adr)->lprev->name);
				((t_part *)adj->adr)->lprev = surg->prev;
					// printf("new Lprev = %s\n", ((t_part *)adj->adr)->lprev->name);
			}
			if (farm->map[surg->prev->idx][((t_part *)adj->adr)->idx].c == -1)
			{
				add_hold(&(p->adj), &(p->ladj), creat_hold(surg->prev, mem));
				return (1);
			}
		}
		adj = adj->next;
	}
// printf ("			***end open surg ***\n");
	return (0);
}

int		shortest_path(t_farm *farm, int v, t_mem *mem)
{
	t_queue	q;
	t_surg	*surg;

	q.first = NULL;
	q.v = v;
// printf("shortest_path\n");
	enqueue(&q, farm->start, mem);
	while (1)
	{
		if (!(surg = dequeue(&q)))
			return (0);
		if ((open_surg(&q, surg, farm, mem)))
			return (1);
	}
	return (0);
}
