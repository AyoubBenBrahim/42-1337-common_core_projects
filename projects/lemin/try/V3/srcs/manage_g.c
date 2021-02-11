
#include "../inc/lem_in.h"

// void	ft_save_samllest_score(t_parse *prs, t_groups *groups,
// 	t_list_node *paths)
// {
// 	prs->small_score_group = groups;
// 	prs->small_score_path = paths;
// 	prs->save_smallest_score = paths->local_score;
// }

void	create_first_group(t_parse *prs, int path_length)
{
	t_groups	*groups;
	t_list_node	*paths;

	prs->re_groupe = (t_groups *)ft_memalloc(sizeof(t_groups));
	groups = prs->re_groupe;
	groups->group_id = prs->group_id++;
	groups->next_gr = NULL;
	groups->path_node = (t_list_node *)ft_memalloc(sizeof(t_list_node));
	paths = groups->path_node;
	paths->next = NULL;
	paths->path_verteces = path_length;
	paths->path = ft_strdup_int(prs->path, 0, path_length);
	groups->merged_paths = ft_strdup_int(prs->path, 1, path_length - 2);
	groups->nbr_paths = 1;
	paths->path_id = 1;
	groups->merged_paths_length = path_length - 2;
	groups->total_verteces = path_length;
	// paths->local_score = prs->nbr_ants + paths->path_verteces - 2;
	groups->last_ptr = paths;
	quick_sort(groups->merged_paths, 0, groups->merged_paths_length - 1);
	prs->last_reg = groups;
	// if (!prs->save_smallest_score
	// 	|| paths->local_score < prs->save_smallest_score)
	// 	ft_save_samllest_score(prs, groups, paths);
}

void	store_in_same_group(t_parse *prs, t_groups **group_to_store,
			int path_length)
{
	t_list_node	*new_path;
	int			*sv;
	int			len;
	t_list_node *p;
	t_list_node *tmp;
	int id;

	new_path = (t_list_node *)ft_memalloc(sizeof(t_list_node));
	new_path->path = ft_strdup_int(prs->path, 0, path_length);
	new_path->path_verteces = path_length;

(*group_to_store)->nbr_paths++;
// new_path->path_id = (*group_to_store)->nbr_paths++;

	if (path_length < (*group_to_store)->path_node->path_verteces)
	{
		// printf("*-head*--\n");
		new_path->next = (*group_to_store)->path_node;
		(*group_to_store)->path_node = new_path;

		(*group_to_store)->path_node->path_id = 1;
		(*group_to_store)->path_node->next->path_id = 2;

	}
	else if (path_length >= (*group_to_store)->last_ptr->path_verteces)
	{
		// printf("elseIF\n");
		(*group_to_store)->last_ptr->next = new_path;
		new_path->next = NULL;
		(*group_to_store)->last_ptr = new_path;

		new_path->path_id = (*group_to_store)->nbr_paths;
	}
	else
	{
		// printf("else\n");
		p = (*group_to_store)->path_node;
		while (p)
		{
			if (path_length <= p->next->path_verteces)
			{
				// printf("	found\n");
				new_path->next = p->next;
				new_path->path_id = p->path_id + 1;
				p->next->path_id = p->path_id + 2;
				p->next = new_path;
				break ;
			}
			// printf("next\n");
			p = p->next;
		}
	}



	len = (*group_to_store)->merged_paths_length;
	sv = (*group_to_store)->merged_paths;
	(*group_to_store)->merged_paths = join_tab_int(prs->path + 1,
		(*group_to_store)->merged_paths, path_length - 2, len);
	ft_strdel_int(&sv);
	(*group_to_store)->merged_paths_length = len + path_length - 2;
	// (*group_to_store)->last_ptr = new_path;
	(*group_to_store)->total_verteces += path_length;

 	// int nbr1;
 	// int nbr2;
 	// nbr1 = prs->nbr_ants + (*group_to_store)->total_verteces - 2 * (*group_to_store)->nbr_paths;
	// nbr2 = (*group_to_store)->nbr_paths;
	//  new_path->local_score = (nbr1 % nbr2 == 0) ? nbr1/nbr2 : (nbr1/nbr2) + 1;


	// if (new_path->local_score < prs->save_smallest_score)
	// 	ft_save_samllest_score(prs, *group_to_store, new_path);
}

void	create_new_group(t_parse *prs, int path_length, t_groups **last_grp_ptr)
{
	t_groups	*groups;
	t_list_node	*paths;
	// int			id;

	groups = (t_groups *)ft_memalloc(sizeof(t_groups));
	// id = groups->group_id;
	groups->group_id = prs->group_id++;
	(*last_grp_ptr)->next = groups;
	(*last_grp_ptr) = groups;
	(*last_grp_ptr)->path_node =
		(t_list_node *)ft_memalloc(sizeof(t_list_node));
	paths = (*last_grp_ptr)->path_node;
	paths->next = NULL;
	paths->path_verteces = path_length;
	paths->path = ft_strdup_int(prs->path, 0, path_length);
	groups->merged_paths = ft_strdup_int(prs->path, 1, path_length - 2);
	groups->nbr_paths = 1;
	paths->path_id = 1;
	groups->last_ptr = paths;
	groups->total_verteces = path_length;
	paths->local_score = prs->nbr_ants + paths->path_verteces - 2;
	// groups->group_id = id + 1;
	groups->merged_paths_length = path_length - 2;
	quick_sort(groups->merged_paths, 0, groups->merged_paths_length - 1);
	// if (paths->local_score < prs->save_smallest_score)
	// 	ft_save_samllest_score(prs, groups, paths);
}
