/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   augment_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:34:11 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:34:14 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	augment_flow(t_farm *farm)
{
	t_part	*prev;
	t_part	*next;

	next = farm->end->ladj->adr;
	farm->map[next->idx][farm->end->idx].c = 0;
	farm->map[next->idx][farm->end->idx].f = 1;
	prev = next->lprev;
	while (prev != farm->start)
	{
		(farm->map[prev->idx][next->idx].c)--;
		(farm->map[prev->idx][next->idx].f)++;
		(farm->map[next->idx][prev->idx].c)++;
		(farm->map[next->idx][prev->idx].f)--;
		if (farm->map[prev->idx][next->idx].f)
			next->prev = next->lprev;
		next = prev;
		prev = next->lprev;
	}
	(farm->map[prev->idx][next->idx].c)--;
	(farm->map[prev->idx][next->idx].f)++;
	next->prev = next->lprev;
}
