/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:36:37 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:36:41 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

long	get_score(t_path *path, long ants)
{
	long	l;
	long	d;

	d = 0;
	l = path->l;
	while (ants > 0)
	{
		while (path && path->l == l)
		{
			d++;
			path = path->next;
		}
		if ((ants -= d) > 0)
			l++;
	}
	return (l);
}
