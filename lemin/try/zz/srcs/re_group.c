
#include "../inc/lem_in.h"

// void print__path(t_parse *prs, int *path, int len)
// {
// 	int i;

// 	for (i = 0; i < len; i++)
// 		printf("%s->", prs->array_of_rooms[path[i]]);
// 	printf("\n");
// }

void	detect_path_group(t_parse *prs, int *path, int path_length)
{
	t_groups	*groups;
	t_list_node	*paths;
	int			intersect;// change to tboolean better
	int			i;

// printf("=========path ======== ");
// print__path(prs, path, path_length);

	groups = prs->last_created_grp;
	paths = prs->the_group->path_holder;
	while (paths)
	{
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
			prs->path_length = paths->path_verteces;
			store_in_same_grp(prs);
		}
		// printf("	----------\n");
		paths = paths->next;
	}
	// printf("========================\n");
}

void re_groupe(t_parse *prs)
{
	t_list_node	*paths;
	// t_groups	*grp_iterator;

	// grp_iterator = prs->the_group;
	// paths = grp_iterator->path_holder;
	paths = prs->the_group->path_holder;
	while (paths)
	{
		// prs->detected = NULL;
		prs->path = paths->path;
		prs->path_length = paths->path_verteces;
		create_new_grp(prs);
		detect_path_group(prs, paths->path, paths->path_verteces);
		paths= paths->next;
	}
}
