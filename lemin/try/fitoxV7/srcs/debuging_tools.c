
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

    printf("\n\nSCORE = %d\n", prs->smallest_score);
    printf("\ngroup = %d\n", prs->best_score_grp->group_id);
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

void count_adjs(t_parse *prs)
{
    t_graph *gr;
    int v;
    t_list_node *room;
    t_list_node *tmp1;
    t_list_node *tmp2;
    t_list_node *new;

    int counter;


    // tmp1 = prs->graph->tab[5].list;
    // while (tmp1)
    // {
    //     if (!tmp1->next)
    //     {
    //         new = ft_create_list_node(prs->start_index);
    //         new->next = NULL;
    //         tmp1->next = new;
    //         break ;
    //     }
    //     tmp1 = tmp1->next;
    // }

/*
printf("ADD TO ADJ [%s]\n", prs->array_of_rooms[5]);
	t_list_node *head;
    gr = prs->graph;
	head = gr->tab[5].list;
	printf("head [%s]\n", prs->array_of_rooms[(head)->dst]);
	new = ft_create_list_node(prs->start_index);


    tmp1 = head;
    new->next = head;
printf("new->next = %s\n", prs->array_of_rooms[new->next->dst]);
printf("head = %s\n", prs->array_of_rooms[head->dst]);

	head = new;
printf("head = %s\n", prs->array_of_rooms[head->dst]);
*/

    // print_graph(prs);
    // exiter

    gr = prs->graph;
    v = 0;
    while (v < gr->nb_v)
    {
        room = gr->tab[v].list;
        counter = 0;
        // printf("==== v =  %s==== \n", prs->array_of_rooms[v]);
        if (v == prs->end_index)
        {
            // gr->tab[v].list = NULL;
            free_list(prs, &gr->tab[v].list);
        }
/*
        else
        {
            tmp1 = NULL;
            tmp2 = NULL;
            tmp1 = room;
            if (tmp1->next)
                tmp2 = tmp1->next;
            while (tmp1)
            {
                // printf("ROOM =  %s\n", prs->array_of_rooms[tmp1->dst]);
                if (tmp1->dst == prs->start_index)
                {

                    room = tmp1;
                    free(room);
                    room = NULL;
                    tmp1 = tmp2;
                    break;
                }
                else if (tmp2 && tmp2->dst == prs->start_index)
                {
                    room = tmp2;
                    tmp2 = tmp2->next;
                    free(room);
                    room = NULL;
                    tmp1->next = tmp2;
                    break;
                }
                if (tmp2)
                    tmp2 = tmp2->next;
                counter++;
                tmp1 = tmp1->next;
            }
        }
*/
        if (gr->tab[v].list)
            gr->tab[v].list->nbr_edges = counter;
        v++;
    }
}

void    print_adj_addr(t_parse *prs)
{
    t_list_node *list;

    int i = 0;
    while (i < prs->total_vertices)
    {
        list = prs->graph->tab[i].list;
        printf("\n        ***** list of room [%s, %d] **** \n\n", prs->array_of_rooms[i], i);
        while (list)
        {
            printf("name = |%s| ptr = |%p|\n", prs->array_of_rooms[list->dst], list);
            list = list->next;
        }
        i++;
    }
}
