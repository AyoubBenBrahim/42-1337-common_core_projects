/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:19:58 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/10 09:39:58 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	share_ants(t_farm *farm)
{
	int		ants;
	long	score;
	t_path	*path;
	int		c;

	ants = farm->ants;
	score = farm->score;
	path = farm->path;
	while (ants)
	{
		c = score - path->l + 1;
		if (ants > c)
		{
			path->nb = c;
			ants = ants - c;
		}
		else
		{
			path->nb = ants;
			ants = 0;
		}
		path = path->next;
	}
}
