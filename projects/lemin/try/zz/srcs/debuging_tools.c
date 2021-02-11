
#include "../inc/lem_in.h"

void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d* ", array[i]);
    printf("\n");
}

void print_groups(t_parse *prs)
{
    t_groups *group;
    t_list_node *paths;

    group = prs->the_group;

    while (group)
    {
        printf("=================G[%d]==============\n", group->group_id);
        // printf("group score = %d\n", group->global_score);
        paths = group->path_holder;
        while (paths)
        {
            printf("    len %d\n", paths->path_verteces);
            for (int i = 0; i < paths->path_verteces; i++)
                printf("%s|", prs->array_of_rooms[paths->path[i]]);
            printf("\n");
            paths = paths->next;
            printf("---------\n");
        }
        // printf("===============\n\n");
        group = group->next;
    }

    if (prs->smallest_score)
   {
        printf("\n\nSCORE = %d\n", prs->smallest_score);
        printf("\ngroup = %d\n", prs->best_score_grp->group_id);
    }
}

void groups(t_parse *prs)
{
    t_groups *group;
    t_list_node *paths;

    group = prs->the_group;

    while (group)
    {
        printf("G[%d]\n", group->group_id);
        paths = group->path_holder;
        group = group->next;
    }
}

void groups2(t_parse *prs)
{
    t_groups *group;
    t_list_node *paths;

    group = prs->the_group;

    while (group)
    {
        printf("=================G[%d]==============\n", group->group_id);

        // printf("nbr path = %d\n\n", group->nbr_paths);

        paths = group->path_holder;
        while (paths)
        {
            // printf("s = %d\n\n", paths->local_score);
            printf("%d - %s| %d", paths->local_score, prs->array_of_rooms[paths->path[1]], paths->path_verteces);
            printf("\n");
            paths = paths->next;
        }
        group = group->next;
    }
    printf("\n\nSCORE = %d\n", prs->smallest_score);
    printf("\ngroup = %d\n", prs->best_score_grp->group_id);
}

void print_this_group(t_parse *prs, t_groups *group)
{
    t_list_node *paths;

    // group = prs->the_group;


        printf("=================G[%d]==============\n", group->group_id);
        // printf("group score = %d\n", group->global_score);

        paths = group->path_holder;
        while (paths)
        {
            printf("    sc, len[%d, %d]\n", paths->local_score, paths->path_verteces);
            for (int i = 0; i < paths->path_verteces; i++)
                printf("%s|", prs->array_of_rooms[paths->path[i]]);
            printf("\n");
            paths = paths->next;
            printf("---------\n");
        }
        // printf("===============\n\n");


    printf("\n\nSCORE = %d\n", prs->smallest_score);
    printf("\ngroup = %d\n", prs->best_score_grp->group_id);
}

void print_graph(t_parse *prs)
{

    t_graph *gr;
    int v;
    t_list_node *room;

    gr = prs->graph;
    v = 0;
    printf("gr->nb_v = %d\n", gr->nb_v);

    while (v < gr->nb_v)
    {
        room = gr->tab[v].list;

        // printf("\nAdjacency list of vertex [%s, %d]\n", prs->array_of_rooms[v], v);

        printf("\nAdjacency list of vertex [%s, %d]\n", prs->array_of_rooms[gr->tab[v].root->dst], v);
        while (room)
        {
            // printf("    dst = ");
            printf(" remain |%d| \n", room->remaining);
             printf("%s [%d] cf[%d, %d]\n", prs->array_of_rooms[room->dst], room->edge_cap, room->c, room->f);
            // printf("    edge_cap = %d\n", room->edge_cap);
            room = room->next;
        }
        v++;
        printf("*********************************\n");
    }
}
// void	print_lst(t_parse prs, t_vertices *lst)
// {
// 	{
// 		printf ("%s ", lst->vertex_name);
// 		printf ("%d ", lst->coord_x);
// 		printf ("%d", lst->coord_y);
// 		printf ("\n");
// 		lst = lst->next;
// 	}
// }

void free_list(t_parse *p, t_list_node **adj)
{
    t_list_node *tmp;
    // if (!lst)
    // 	return ;
    while (*adj != NULL)
    {
        // printf("here\n");
        tmp = (*adj)->next;
        free(*adj);
        *adj = tmp;
    }

    *adj = NULL;
}

t_boolean check_if_duplicat(t_parse *prs)
{
    t_list_node	*paths_iterator;
    int len1;
    int len2;

    len1 = prs->path_length;
	paths_iterator = prs->the_group->path_holder;
	while (paths_iterator)
	{
        len2 = paths_iterator->path_verteces;
        if (len2 == len1)
        {
            if (paths_iterator->path[1] == prs->path[1] && paths_iterator->path[len2 - 2] == prs->path[len1 - 2])
                if (paths_iterator->path[2] == prs->path[2] && paths_iterator->path[len2 - 3] == prs->path[len1 - 3])
                        return (TRUE);
        }
		paths_iterator = paths_iterator->next;
	}
    return (FALSE);
}
