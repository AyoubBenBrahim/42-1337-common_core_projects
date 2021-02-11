/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:34:04 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/07 11:45:59 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void print_pathh(t_path *path)
// {
// 	int i = 1;

// 	printf ("** shortest =  **\n");
// 	t_room *room;
// 	room = path->end_ptr;
// 	printf("--id = %d: --l=%d\n", i++, path->l);
// 	while (room)
// 	{
// 		printf("%s|", room->name);
// 		room = room->prev;
// 	}
// 	printf("\n\n");
// }

t_path	*get_path(t_farm *farm, int v, t_mem *mem)
{
	t_path	*path;


	if (!(shortest_path(farm, v, mem)))
		return (0);
	augment_flow(farm);
	path = creat_path(farm, mem);

// print_pathh(path);

// exit (0);





	return (path);
}

void	find_sol(t_farm *farm, t_mem *mem)
{
	t_path	*path;
	long	score;
	int		v;


	v = 1;
	if (!(farm->path = get_path(farm, v++, mem)))
		error(mem);
	farm->score = get_score(farm->path, farm->ants);
	while (1)
	{
		if (farm->ants == 1 || !(path = get_path(farm, v++, mem)))
			break ;
		score = get_score(path, farm->ants);


		//***************
		// t_room *room;
		// t_path *p;
		// p = path;

		// room = p->end_ptr;
		// while (room)
		// {
		// 	printf("%s|", room->name);
		// 	room = room->prev;
		// }
		// printf("\n\n");
		//***************

		// printf("%s|", path->parc->name);
		// printf("\n");

		if (score > farm->score)
			break ;
		farm->path = path;
		farm->score = score;
	}
}
