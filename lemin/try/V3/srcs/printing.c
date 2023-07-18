/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:42:20 by ayb*****          #+#    #+#             */
/*   Updated: 2020/10/20 14:38:46 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/lem_in.h"

void send_ants(t_parse *prs)
{

    t_groups *group;
    t_list_node *paths;
    t_boolean   allocated;
    t_boolean   all_ants_reached_end;
    int best_score_path_id;


    group = prs->small_score_group? prs->small_score_group : prs->store_regular_path;
    best_score_path_id = prs->small_score_path? prs->small_score_path->path_id : group->last_ptr->path_id;
    ft_balance_paths(prs, group, best_score_path_id);
    printf("\n\n");// del

    allocated = FALSE;

    // paths = group->path_node;

    // while (paths)
    // { 
    //     if (paths->path_id == 1)
    //         paths->starting_ant = 1;
    //     if (paths->next)
    //         paths->next->starting_ant = paths->starting_ant + paths->path_capacity; //4

    //     paths->waiting_room = paths->starting_ant - 1; // 0 // 3 
    //    paths = paths->next;
    // }

 paths = group->path_node;

    // printf("here/n");
    while (paths)
    {
        if (paths->path_id == 1)
            paths->starting_ant = 1;
        if (paths->next)
            paths->next->starting_ant = paths->starting_ant + paths->path_capacity; //4

        paths->waiting_room = paths->starting_ant - 1; 
        printf("id = %d Cap = %d ",paths->path_id, paths->path_capacity);
        printf("start = %d\n", paths->starting_ant);
       paths = paths->next;
    }
    printf("best path = %d\n", best_score_path_id);
    printf("\n\n");

    int line_counter = 0;
    int i;
    all_ants_reached_end = FALSE;
int all_ants = 0;
   
    while (all_ants != prs->nbr_ants)
    {
        paths = group->path_node;
        while (paths)
        {
            if (!allocated)
            {
                paths->track_ants = (int *)ft_memalloc(paths->path_verteces * sizeof(int));
            }
            i = 0;
            while (i < paths->path_verteces - 1)
            {
                if (paths->track_ants[i + 1] != 0)
                {
                    paths->track_ants[i] = paths->track_ants[i + 1];
                    paths->track_ants[i + 1] = 0;
                    if (paths->track_ants[i] <= prs->nbr_ants && paths->track_ants[i] < paths->starting_ant + paths->path_capacity)
                    {
                        printf("L%d-%s ", paths->track_ants[i], prs->array_of_rooms[paths->path[i]]);
                        if (i == 0 && paths->track_ants[i] > 0)
                            paths->track_ants[0] = -1;
                    }
                    if (i == 0 && paths->track_ants[i] == -1)
                        all_ants++;
                }
                if (i + 2 == paths->path_verteces - 1)
                {
                    paths->waiting_room++;
                    paths->track_ants[paths->path_verteces - 1] = paths->waiting_room;
                }
                i++;
            }
            paths = paths->next;
        }
        printf("\n");
       line_counter++;
        allocated = TRUE;
    }

printf("\nnbr lines = %d\n", line_counter);

}