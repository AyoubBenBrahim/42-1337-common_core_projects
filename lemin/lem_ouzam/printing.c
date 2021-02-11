/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 09:52:12 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/10 09:39:12 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_farm(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

void	print_path(t_path *path, int *ants, int *ant_end)
{
	t_room *room;

	room = path->end_ptr;
	while (!cmpstr(path->parc->name, room->name))
	{
		if (room->prev->ant != 0)
		{
			room->ant = room->prev->ant;
			room->prev->ant = 0;
			print_farm(room->ant, room->name);
			if (room == path->end_ptr)
				(*ant_end)++;
		}
		room = room->prev;
	}
	if (path->nb)
	{
		path->parc->ant = *ants;
		print_farm(*ants, path->parc->name);
		(*ants)++;
		(path->nb)--;
	}
}

void	printing(t_farm *farm)
{
	t_path	*paths;
	int		ant_end;
	int		ants;

	ant_end = 0;
	ants = 1;
	while (ant_end != farm->ants)
	{
		paths = farm->path;
		while (paths)
		{
			print_path(paths, &ants, &ant_end);
			paths = paths->next;
		}
		ft_putstr("\n");
	}
}
