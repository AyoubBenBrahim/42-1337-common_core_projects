
#include "../inc/lem_in.h"

int		ft_strdel_int(int **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
	return (1);
}

// void	ft_save_samllest_score(t_parse *prs, t_groups *groups,
// 	t_list_node *paths)
// {
// 	prs->best_score_grp = groups;
// 	prs->best_score_pat = paths;
// 	prs->smallest_score = paths->local_score;
// }

void	create_group(t_parse *prs)
{
	t_groups	*groups;
	t_list_node	*paths;

	prs->the_group = (t_groups *)ft_memalloc(sizeof(t_groups));
	prs->the_group->group_id = prs->group_id++;
	prs->the_group->next = NULL;
	prs->the_group->path_holder = (t_list_node *)ft_memalloc(sizeof(t_list_node));
	paths = prs->the_group->path_holder;
	paths->next = NULL;
	paths->path_verteces = prs->path_length;
	paths->path = ft_strdup_int(prs->path, 0, prs->path_length);
	prs->the_group->merged_paths = ft_strdup_int(prs->path, 1, prs->path_length - 2);
	prs->the_group->nbr_paths = 1;
	paths->path_id = 1;
	prs->the_group->merged_paths_length = prs->path_length - 2;
	prs->the_group->total_verteces = prs->path_length;
	paths->local_score = prs->nbr_ants + paths->path_verteces - 2;
	prs->the_group->last_ptr = paths;
	quick_sort(prs->the_group->merged_paths, 0, prs->the_group->merged_paths_length - 1);
	prs->last_created_grp = prs->the_group;
	// if (!prs->smallest_score
	// 	|| paths->local_score < prs->smallest_score)
	// 	ft_save_samllest_score(prs, prs->the_group, paths);
}

// void store_in_same_grp(t_parse *prs, t_groups **selected_grp, int path_length)
// void store_in_same_grp(t_parse *prs, t_groups **selected_grp)
void store_in_same_grp(t_parse *prs)
{
	t_list_node *new_path;
	int *sv;
	int len;
	t_list_node *p;
	t_list_node *tmp;
	int id;

	new_path = (t_list_node *)ft_memalloc(sizeof(t_list_node));
	new_path->path = ft_strdup_int(prs->path, 0, prs->path_length);
	new_path->path_verteces = prs->path_length;
	prs->last_created_grp->nbr_paths++;
	if (prs->path_length < prs->last_created_grp->path_holder->path_verteces)
	{
		new_path->next = prs->last_created_grp->path_holder;
		prs->last_created_grp->path_holder = new_path;

		prs->last_created_grp->path_holder->path_id = 1;
		prs->last_created_grp->path_holder->next->path_id = 2;
	}
	else if (prs->path_length >= prs->last_created_grp->last_ptr->path_verteces)
	{
		prs->last_created_grp->last_ptr->next = new_path;
		new_path->next = NULL;
		prs->last_created_grp->last_ptr = new_path;

		new_path->path_id = prs->last_created_grp->nbr_paths;
	}
	else
	{
		p = prs->last_created_grp->path_holder;
		while (p)
		{
			if (prs->path_length <= p->next->path_verteces)
			{
				new_path->next = p->next;
				new_path->path_id = p->path_id + 1;
				p->next->path_id = p->path_id + 2;
				p->next = new_path;
				break;
			}
			p = p->next;
		}
	}

	len = prs->last_created_grp->merged_paths_length;
	sv = prs->last_created_grp->merged_paths;
	prs->last_created_grp->merged_paths = join_tab_int(prs->path + 1,
		prs->last_created_grp->merged_paths, prs->path_length - 2, len);
	ft_strdel_int(&sv);
	prs->last_created_grp->merged_paths_length = len + prs->path_length - 2;
	prs->last_created_grp->total_verteces += prs->path_length;
}

void	create_new_grp(t_parse *prs)
{
	t_groups	*groups;
	t_list_node	*paths;

	groups = (t_groups *)ft_memalloc(sizeof(t_groups));
	groups->group_id = prs->group_id++;
	prs->last_created_grp->next = groups;
	prs->last_created_grp = groups; // make it the last thing
	prs->last_created_grp->path_holder = (t_list_node *)ft_memalloc(sizeof(t_list_node));
	paths = prs->last_created_grp->path_holder;
	paths->next = NULL;
	paths->path_verteces = prs->path_length;
	paths->path = ft_strdup_int(prs->path, 0, prs->path_length);
	groups->merged_paths = ft_strdup_int(prs->path, 1, prs->path_length - 2);
	groups->nbr_paths = 1;
	paths->path_id = 1;
	groups->last_ptr = paths;
	groups->total_verteces = prs->path_length;
	paths->local_score = prs->nbr_ants + paths->path_verteces - 2;
	// groups->group_id = id + 1;
	groups->merged_paths_length = prs->path_length - 2;
	quick_sort(groups->merged_paths, 0, groups->merged_paths_length - 1);
	// if (paths->local_score < prs->smallest_score)
	// 	ft_save_samllest_score(prs, groups, paths);
}
