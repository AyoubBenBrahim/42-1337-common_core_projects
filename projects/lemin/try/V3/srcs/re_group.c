
#include "../inc/lem_in.h"

void print__path(t_parse *prs, int *path, int len)
{
	int i;

	for (i = 0; i < len; i++)
		printf("%s->", prs->array_of_rooms[path[i]]);
	printf("\n");
}

void	detect_path_group(t_parse *prs, int *path, int path_length)
{
	t_groups	*groups;
	t_list_node	*paths;
	int			intersect;
	int			i;

// printf("=========path ======== ");
// print__path(prs, path, path_length);

	groups = prs->reg_last_ptr;
	paths = prs->store_regular_path->path_node;
	while (paths)
	{
		// printf("	-----with-----\n");
		// print__path(prs, paths->path, paths->path_verteces);

		// printf("merged =");
		// print__path(prs, groups->merged_paths, groups->merged_paths_length);
		intersect = -2;

		i = -1;
		while (++i < paths->path_verteces)
		{
			// printf("path[i %d] = %s\n",i, prs->array_of_rooms[paths->path[i]]);
			intersect = ft_binary_int_search(groups->merged_paths,
										groups->merged_paths_length, paths->path[i]);
			if (intersect >= 0)
			{
				// printf("	intersect %s\n", prs->array_of_rooms[paths->path[i]]);
				break ;
			}
		}
		if (intersect < 0)
		{
			// printf("not intersect\n");
			prs->path = paths->path;
			ft_store_in_same_group(prs, &prs->reg_last_ptr,  paths->path_verteces);
			// if (!prs->detected)
			// {
			// 	prs->detected = paths;
			// 	prs->last_p = prs->detected;
			// 	prs->detected->next_p = NULL;
			// 	printf("stored = ");
			// 		print__path(prs, prs->detected->path, prs->detected->path_verteces);

			// }
			// else
			// {
			// 	prs->last_p->next_p = paths;
			// 	prs->last_p = paths;
			// 	prs->last_p->next_p = NULL;
			// }
		}
		// printf("	----------\n");
		paths = paths->next;
	}
	// printf("========================\n");
}

void re_groupe(t_parse *prs)
{
	t_list_node	*paths;
	t_groups	*groups;

	groups = prs->store_regular_path;
	paths = groups->path_node;
	// prs->re_groupe = NULL;
	// prs->reg_last_ptr = NULL;
	// prs->path = paths->path;
	// create_first_group(prs, &prs->re_groupe, paths->path_verteces);
	while (paths)
	{
		prs->detected = NULL;
		// prs->last_p = NULL;
		prs->path = paths->path;
		ft_create_new_group(prs, paths->path_verteces, &prs->reg_last_ptr);
		// printf("		*1*last= %d\n", prs->reg_last_ptr->group_id);
		detect_path_group(prs, paths->path, paths->path_verteces);
		// printf("		*2*last= %d\n", prs->reg_last_ptr->group_id);
		// if (prs->detected)
		// {
		// 	t_list_node *tmp;
		// 	tmp = prs->detected;

		// 	while (tmp)
		// 	{
		// 		prs->path = tmp->path;
		// 		ft_store_in_same_group(prs, &prs->reg_last_ptr,  tmp->path_verteces);
		// 		tmp = tmp->next_p;
		// 	}
		// }

		paths= paths->next;
	}
}
