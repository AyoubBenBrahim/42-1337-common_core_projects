
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

    group = prs->store_regular_path;

    while (group)
    {
        printf("=================G[%d]==============\n", group->group_id);
        // printf("group score = %d\n", group->global_score);

        paths = group->path_node;
        while (paths)
        {
            // printf("                **score = %d **\n", paths->local_score);
            for (size_t i = 0; i < paths->path_verteces; i++)
                printf("%s|", prs->array_of_rooms[paths->path[i]]);
            printf("\n");
            paths = paths->next;
            printf("---------\n");
        }
        // printf("===============\n\n");
        group = group->next;
    }
}

void groups(t_parse *prs)
{
    t_groups *group;
    t_list_node *paths;

    group = prs->store_regular_path;

    while (group)
    {
        printf("G[%d]\n", group->group_id);
        paths = group->path_node;
        group = group->next;
    }
}

void groups2(t_parse *prs)
{
    t_groups *group;
    t_list_node *paths;

    group = prs->store_regular_path;

    while (group)
    {
        printf("=================G[%d]==============\n", group->group_id);

        // printf("nbr path = %d\n\n", group->nbr_paths);

        paths = group->path_node;
        while (paths)
        {
            // printf("s = %d\n\n", paths->local_score);
            printf("%d - %s| %d",paths->local_score, prs->array_of_rooms[paths->path[1]], paths->path_verteces);
            printf("\n");
            paths = paths->next;
        }
        group = group->next;
    }
}

void print_graph(t_parse *prs)
{

    t_graph *gr;
    int v;
    t_list_node *tmp;

    gr = prs->graph;
    v = 0;
    // prs = getset(0);
    printf("gr->nb_v = %d\n", gr->nb_v);

    while (v < gr->nb_v)
    {
        tmp = gr->tab[v].list;
        printf("\n Adjacency list of vertex %s\n head ", prs->array_of_rooms[v]);

        while (tmp)
        {
            // printf("\ndst = %s\n", prs->array_of_rooms[tmp->dst]);
            printf("\ndst = %s\n", prs->array_of_rooms[tmp->dst]);
            printf("flow = %d\n", tmp->flow);
            if (tmp->next)
                printf("\n-\n");
            tmp = tmp->next;
        }
        v++;
        printf("\n");
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

