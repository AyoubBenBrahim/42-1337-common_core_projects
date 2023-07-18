/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:36:12 by ayb*****          #+#    #+#             */
/*   Updated: 2020/11/05 10:36:14 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_surg	*creat_surg(t_part *part, t_mem *mem)
{
	t_surg	*surg;

// printf("		=create_surg== prev= |%s|\n", part->name);

	surg = ft_malloc(sizeof(t_surg), mem);
	surg->prev = part;
	surg->adj = part->adj;
	surg->next = NULL;
// printf("		=end create_surg==\n");
	return (surg);
}

int		enqueue(t_queue *q, t_part *part, t_mem *mem)
{
	t_surg	*surg;

// printf("	=enqeu== part = |%s|\n", part->name);

	surg = creat_surg(part, mem);
	if (q->first)
	{
		q->end->next = surg;
		q->end = surg;
	}
	else
	{
		q->first = surg;
		q->end = surg;
	}
// printf("====\n");
	return (0);
}

t_surg	*dequeue(t_queue *q)
{
	t_surg	*hld;

	hld = NULL;
	if (q->first)
	{
		hld = q->first;
		q->first = q->first->next;
	}
	return (hld);
}
