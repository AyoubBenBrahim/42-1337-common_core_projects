
#include "../inc/lem_in.h"

void init_discovered(t_parse *prs)
{
	int row;
	int column;
	int i;
	int j;

	row = 3;
	column = prs->total_vertices;
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if (!(i ==  1 && prs->discovered[i][j] == prs->start_index))
				prs->discovered[i][j] = -1;
			j++;
		}
		i++;
	}
}

void print_discovered(t_parse *prs)
{
	int row;
	int column;
	int i;
	int j;

	printf ("\n\n **** print discovered ****\n");

	int k = 0;
	while (k < prs->total_vertices)
		printf("%5s|", prs->array_of_rooms[k++]);
	printf("\n");

	k = 1;
	while (k++ < prs->total_vertices)
		printf("-------");
	printf("\n");

	row = 3;
	column = prs->total_vertices;
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if (i == 0)
				printf("%5d|", prs->discovered[0][j]);
			if (i == 1)
			{
				if (prs->discovered[1][j] >= 0)
					printf("%5s|", prs->array_of_rooms[prs->discovered[1][j]]);
				else
					printf("%5d|", prs->discovered[1][j]);
			}
			if (i == 2)
				printf("%5d|", prs->discovered[2][j]);
			j++;
		}

		printf ("\n");
		i++;
	}
}

void bfs_init(t_parse *prs)
{
	int i;
	int row;
	int column;

	row = 3;
	column = prs->total_vertices;

	prs->discovered = (int **)ft_memalloc(sizeof(int *) * row);
	i = 0;
	while (i < row)
		prs->discovered[i++] = (int *)ft_memalloc(sizeof(int) * column);
	init_discovered(prs);

	// printf("\n");
}

void print_stack(t_parse *prs)
{
	t_stack *stack;

	stack = prs->stack;
	if (stack)
	{
		// printf("-- print stack-[%d]- \n", prs->stack_len);
		printf("-- print stack -- \n");
		while (stack)
		{
			printf("|%s, ", prs->array_of_rooms[stack->room]);
			printf("[%s], %d|\n", prs->array_of_rooms[stack->parent->room], stack->len);
			stack = stack->next;
		}
	}
	else
		printf("EMPTY STACK\n");
}

t_list_node *get_child(t_list_node *parent, int child_to_search)
{
	t_list_node *p;

	p = parent;
	while (p)
	{
		if (p->dst == child_to_search)
			return (p);
		p = p->next;
	}
	return (NULL);
}

void edit_edge_cap(t_parse *prs, t_stack *parent, t_stack *child)
{
	t_list_node *parent_adj;
	t_list_node *child_adj;
	t_list_node *oposit_child_adj;

	parent_adj = prs->graph->tab[parent->room].list;
	child_adj = get_child(parent_adj, child->room);
	child_adj->edge_cap = 0;

	// check the oposit edge
	// parent_adj = prs->graph->tab[child->room].list;

	// end->j->g->e->start
}

void print_path(t_parse *prs)
{
	printf("\nhere is the path len = {%d}:\n\n", prs->path_length);

	int k = 0;
	printf("{%s}", prs->array_of_rooms[prs->path[k++]]);
	while (k < prs->path_length - 1)
	{
		printf("%s|", prs->array_of_rooms[prs->path[k++]]);
	}
	printf("{%s}\n", prs->array_of_rooms[prs->path[k]]);
	printf("\n");
}

void create_global_grp(t_parse *prs)
{
	if (!prs->the_group)
	{
		create_group(prs);
		return;
	}
	// if (!check_if_duplicat(prs))
		store_in_same_grp(prs);
	// else
	// 	 ft_strdel_int(&(prs->path));

}

void	bfs_start_to_end(t_parse *prs, int the_start)
{
	t_stack *path;
	int i;
	i = 0;
	path = prs->lstack;
	// int parent_is_start;

	while (path->room != the_start)
	{
		edit_edge_cap(prs, path->parent, path);
		// prs->path[i++] = path->room;
		path = path->parent;
	}
	// prs->path[i++] = path->room;
}

void	bfs_end_to_start(t_parse *prs, int the_start)
{
	t_stack *path;
	int i;

	prs->path_length = prs->lstack->len;
	prs->path = (int *)ft_memalloc(sizeof(int) * prs->path_length);

	i = prs->path_length - 1;
	path = prs->lstack;
	while (path->room != the_start)
	{
		edit_edge_cap(prs, path->parent, path);
		prs->path[i--] = path->room;
		path = path->parent;
	}
	prs->path[i] = path->room;

	create_global_grp(prs);

}

void	create_path(t_parse *prs, int the_start)
{

	// printf("=== create path ===\n");

	// prs->nbr_paths++;
	// prs->path_length = prs->lstack->len;
	// prs->path = (int *)ft_memalloc(sizeof(int) * prs->path_length);



	if (the_start == prs->start_index)
		bfs_start_to_end(prs, the_start);
	else
		bfs_end_to_start(prs, the_start);

	// print_path(prs);
// print_discovered(prs);
	// create_global_grp(prs);
}

void adjsOf(t_parse *prs, t_list_node *room, int node)
{
	printf("===adjs of %s ===\n", prs->array_of_rooms[node]);
	while (room)
	{
		printf("[%s] ", prs->array_of_rooms[room->dst]);
		printf("[v %d] ", prs->discovered[0][room->dst]);
		printf("[c %d] \n", room->edge_cap);
		room = room->next;
	}
	printf("================\n");
}

t_boolean shortest_path(t_parse *prs, int the_start, int the_end)
{
	int pushed;
	t_list_node *adj;

	if (!prs->iterator)
	{
		// printf("\n \n **FINISH** \n");
		free_stack(prs);
		return (FALSE);
	}

	adj = prs->graph->tab[prs->iterator->room].list;
	// adjsOf(prs, adj, prs->iterator->room);
	while (adj)
	{
		// if (prs->iterator->room != the_start && !adj->edge_cap)
		// 	prs->there_is_intersection = TRUE;
		if (prs->discovered[0][adj->dst] != prs->visited && adj->edge_cap)
		{
			// printf("	pushable [%s]\n", prs->array_of_rooms[adj->dst]);
			pushed = push(prs, adj->dst, prs->iterator->room);
			prs->discovered[0][adj->dst] = prs->visited;
			if (pushed == the_end)
				break;
		}
		adj = adj->next;
	}
	// print_stack(prs);

	if (prs->lstack->room == the_end)
	{
		create_path(prs, the_start);
		prs->visited++;
		free_stack(prs);
		push(prs, the_start, the_start);
		prs->iterator = prs->stack;
		prs->discovered[0][the_start] = prs->visited;

		shortest_path(prs, the_start, the_end);
		return (TRUE);
	}
	prs->iterator = prs->iterator->next;
	return (TRUE);
}

void	track_predecessor(t_parse *prs)
{
	t_list_node *adjs_of_end;
	int i;

	adjs_of_end = prs->graph->tab[prs->end_index].list;

	while (adjs_of_end)
	{
		printf("end|");
		i = adjs_of_end->dst;
		// prs->path = (int *)ft_memalloc(sizeof(int) * prs->discovered[2][i] + 1);
		int k;
		k = 0;
		if (i != -1)
		{
			printf("%s|", prs->array_of_rooms[i]);
			// prs->path[k++] = prs->end_index;
			// prs->path[k++] = i;
			// prs->path_length = 2;
		}
		while (prs->discovered[1][i] != -1 && i != prs->start_index)
		{
			// if (prs->discovered[1][i] == -1)
			// {
			// 	// ft_strdel_int(&(prs->path));
			// 	break ;
			// }
			printf("%s|", prs->array_of_rooms[prs->discovered[1][i]]);
			// prs->path[k++] = prs->discovered[1][i];
			// prs->path_length++;
			i = prs->discovered[1][i];
		}
		prs->path_length = k;
		// printf("|start\n");
		// prs->path[k] = '\0';

			// print_path(prs);
		// ft_strdel_int(&(prs->path));
		printf("\n\n");
		adjs_of_end = adjs_of_end->next;
	}
}

void		breadth_first_search(t_parse *prs)
{
	bfs_init(prs);
	// prs->there_is_intersection = FALSE;
	prs->visited = 1;

	push(prs, prs->start_index, prs->start_index);
	prs->iterator = prs->stack;
	prs->discovered[0][prs->start_index] = prs->visited;
	while (shortest_path(prs, prs->start_index, prs->end_index))
	{}
	printf("sortir 1\n");
	free_stack(prs);

	// track_predecessor(prs);

	prs->visited++;
	push(prs, prs->end_index, prs->end_index);
	prs->iterator = prs->stack;
	prs->discovered[0][prs->end_index] = prs->visited;
	while (shortest_path(prs, prs->end_index, prs->start_index))
	{}
	// printf("sortir 2\n");
	free_stack(prs);
	// exiter

}

