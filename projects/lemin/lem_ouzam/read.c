/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:36:24 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:36:26 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_farm(t_farm *farm, t_mem *mem)
{
	int		l;

	l = 0;
	if (!(farm->ants = get_ants(mem)))
		error(mem);
	get_nodes(mem, farm);
	if (!(farm->end) || !(farm->start))
		error(mem);
	farm->map = create_map(farm->size + 1, mem);
	get_links(mem, farm);
	if (!(farm->start->adj))
		error(mem);
}
