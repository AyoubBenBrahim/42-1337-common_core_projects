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

void print_path(t_parse *prs, int *path, int len)
{
	int i;

	for (i = 0; i < len; i++)
		printf("%s->", prs->array_of_rooms[path[i]]);
	printf("\n");
}

// void	ft_detect_path_group(t_parse *prs, t_groups *store_path, int *path,
// 		int path_length)
// {
// 	t_groups	*groups;
// 	t_list_node	*paths;
// 	int			found;

// 	groups = store_path;
// 	while (groups)
// 	{
// 		found = -2;
// 		int i;
// 		i = -1;
// 		while (++i < path_length)
// 		{
// 			found = ft_binary_int_search(groups->merged_paths,
// 										groups->merged_paths_length, path[i]);
// 			if (found >= 0)
// 			{
// 				// printf("	intersect %s\n", prs->array_of_rooms[path[i]]);
// 				break ;
// 			}
// 		}
// 		if (found < 0)
// 		{
// 			// printf("not intersect\n");
// 			if (!prs->detected)
// 			{
// 				prs->detected = groups;
// 				prs->last_gr = prs->detected;
// 				prs->detected->next_gr = NULL;
// 			}
// 			else
// 			{
// 				prs->last_gr->next_gr = groups;
// 				prs->last_gr = groups;
// 				prs->last_gr->next_gr = NULL;
// 			}
// 		}
// 		groups = groups->next;
// 	}
// }

void		ft_store_path_in_group(t_parse *prs, int path_length,
		t_groups **store_path, t_groups **last_grp_ptr)
{

	// printf("\n******\n	path = ");print_path(prs, prs->path, path_length);
	// printf("\n");
	if (!*store_path)
	{
		ft_create_first_group(prs, &store_path, path_length,
				last_grp_ptr);
		// printf("first group: ");
		return ;
	}
		ft_store_in_same_group(prs, store_path, path_length);
/*
	prs->detected = NULL;
	ft_detect_path_group(prs, *store_path, prs->path, path_length);
	if (!prs->detected)
	{

			// printf("NEW Group: %d\n", prs->store_regular_path->nbr_paths);
		// print_path(prs, prs->path, path_length);
		ft_create_new_group(prs, path_length, last_grp_ptr);
	}
	else
	{

		t_groups *tmp;
		tmp = prs->detected;
		while(tmp)
		{
			ft_store_in_same_group(prs, &tmp, path_length);
			tmp = tmp->next_gr;
		}
	}
// groups(prs);
	// printf("\n\n");
	*/
}


