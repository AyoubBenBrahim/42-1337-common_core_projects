/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:40:39 by ahel-men          #+#    #+#             */
/*   Updated: 2020/10/29 12:02:13 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	samllest_score(t_parse *prs, t_groups *groups,
	t_list_node *paths)
{
	prs->small_score_group = groups;
	prs->small_score_path = paths;
	prs->save_smallest_score = paths->local_score;
}

void	calc_score(t_parse *prs)
{
	t_groups *group;
    t_list_node *paths;
	int total_verteces;
	int nbr_paths;
	int nbr1;
 	int nbr2;

	prs->save_smallest_score = 0;
	prs->small_score_group = NULL;
	prs->small_score_path = NULL;

    group = prs->store_regular_path;
	group = group->next;
	
    while (group)
    {
		paths = group->path_node;
		total_verteces = 0;
		nbr_paths = 0;
        while (paths)
        {
			total_verteces += paths->path_verteces;
			nbr_paths++;
 			nbr1 = prs->nbr_ants + total_verteces - 2 * nbr_paths;
			nbr2 = nbr_paths;
			paths->local_score = (nbr1 % nbr2 == 0) ? nbr1/nbr2 : (nbr1/nbr2) + 1;
			if (!prs->save_smallest_score
			|| paths->local_score < prs->save_smallest_score)
				samllest_score(prs, group, paths);

			paths = paths->next;
		}
		group = group->next;
	}

}