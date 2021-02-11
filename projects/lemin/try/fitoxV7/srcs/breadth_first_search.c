
#include "../inc/lem_in.h"

void init_discovered(t_parse *prs, int *array, int lenght)
{
	int i;

	i = 0;
	while (i < lenght)
	{
		array[i] = -1;
		i++;
	}
}

void print_discovered(t_parse *prs, int *discovered, int len)
{
	int i = 0;

	printf("print discovered \n");
	while (i < len)
	{
		printf("[%s , %d] -> ", prs->array_of_rooms[i], discovered[i]);
		i++;
	}
	printf("\n");
}

void bfs_init(t_parse *prs)
{
	t_list_node *adj;

	prs->discovered = (int *)ft_memalloc(sizeof(int) * prs->total_vertices);
	init_discovered(prs, prs->discovered, prs->total_vertices);

	printf("\n");
}

void print_stack(t_parse *prs)
{
	t_stack *stack;

	stack = prs->stack;
	if (stack)
	{
		printf("-- print stack-[%d]- \n", prs->stack_len);
		while (stack)
		{
			printf("|%s, ", prs->array_of_rooms[stack->room]);

			if (stack->predecessor)
				printf("%s, [%s], %d, ", prs->array_of_rooms[stack->parent->room], prs->array_of_rooms[stack->predecessor->room], stack->len);
			else
				printf("%s, [NULL], %d, ", prs->array_of_rooms[stack->parent->room], stack->len);
			if (stack->prev)
				printf("%s", prs->array_of_rooms[stack->prev->room]);
			printf("|\n");
			stack = stack->next;
		}
	}
	else
		printf("EMPTY STACK\n");
}

t_list_node *get_child(t_list_node *parent, int child_to_search)
{
	while (parent)
	{
		if (parent->dst == child_to_search)
			return parent;
		parent = parent->next;
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
	parent_adj = prs->graph->tab[child->room].list;
	oposit_child_adj = get_child(parent_adj, parent->room);

	if (!oposit_child_adj->edge_cap)
	{
		// printf("\n\n ** INTERSECT ** \n\n");
		// printf("parent |%s| --> child |%s|\n", prs->array_of_rooms[parent->room],  prs->array_of_rooms[child->room]);
		// printf("intersect child  %s \n", prs->array_of_rooms[child->room]);

		t_stack *stack;
		stack = child->parent;

		while (stack != prs->stack)
		{
			if (stack->room == child->room)
			{
				// printf("found\n");
				// printf("child->pred %s -> %s\n", prs->array_of_rooms[child->room], prs->array_of_rooms[child->predecessor->room]);
				// printf("stack->pred %s -> %s\n", prs->array_of_rooms[stack->room], prs->array_of_rooms[stack->predecessor->room]);

				child->predecessor = stack->predecessor;

				// printf("after: child->pred %s -> %s\n", prs->array_of_rooms[child->room], prs->array_of_rooms[child->predecessor->room]);

				break;
			}
			stack = stack->parent;
		}
	}
	// end->j->g->e->start
}

void print_path(t_parse *prs)
{

	printf("\nhere is the path :\n\n");

	int k = 0;
	printf("{%s}-->", prs->array_of_rooms[prs->path[k++]]);
	while (k < prs->lstack->len - 1)
	{
		printf("|%s|-->", prs->array_of_rooms[prs->path[k++]]);
	}
	printf("{%s}\n", prs->array_of_rooms[prs->start_index]);
}

void create_global_grp(t_parse *prs)
{
	if (!prs->the_group)
	{
		create_group(prs);
		return;
	}
	store_in_same_grp(prs);
}

void create_path(t_parse *prs, int the_start)
{
	t_stack *path;

	int nb_rooms;
	int i;

	// printf("=== create path ===\n");

	prs->nbr_paths++;
	prs->path_length = prs->lstack->len;
	prs->path = (int *)ft_memalloc(sizeof(int) * prs->path_length);

	i = 0;
	path = prs->lstack;
	while (path->room != the_start)
	{
		edit_edge_cap(prs, path->parent, path);
		// printf("%s -> ", prs->array_of_rooms[path->room]);
		prs->path[i++] = path->room;
		path = path->parent;
	}
	prs->path[i++] = path->room;
	// printf("%s\n\n", prs->array_of_rooms[path->room]);

	// print_path(prs);
	ft_strdel_int(&(prs->path));

	prs->lstack->len = 1;
}

void adjsOf(t_parse *prs, t_list_node *room, int node)
{
	printf("===adjs of %s ===\n", prs->array_of_rooms[node]);
	while (room)
	{
		printf("[%s] ", prs->array_of_rooms[room->dst]);
		printf("[v %d] ", prs->discovered[room->dst]);
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
		printf("\n \n **FINISH** \n");
		return (FALSE);
		// exiter
	}

	adj = prs->graph->tab[prs->iterator->room].list;
	// adjsOf(prs, adj, prs->iterator->room);
	while (adj)
	{
		// if (prs->iterator->room != the_start && !adj->edge_cap)
		// 	prs->there_is_intersection = TRUE;
		if (prs->discovered[adj->dst] != prs->visited && adj->edge_cap)
		{
			// printf("	pushable [%s]\n", prs->array_of_rooms[adj->dst]);
			pushed = push(prs, adj->dst, prs->iterator->room);
			prs->discovered[adj->dst] = prs->visited;
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

		t_stack *end;
		end = prs->lstack;
		// repush the start
		push(prs, the_start, the_start);
		prs->lstack->parent = end;

		prs->discovered[the_start] = prs->visited;
		prs->iterator = prs->lstack;
		prs->last_start = prs->lstack;
		// free_stack(prs);
		shortest_path(prs, the_start, the_end);
		return (TRUE);
	}
	prs->iterator = prs->iterator->next;
	return (TRUE);
}

void track_real_predecessors(t_parse *prs)
{
	// t_stack *pred;
	t_list_node *adjs_of_end;

	printf(" *** real predecessors ** \n\n");

	// pred = prs->lstack;
	adjs_of_end = prs->graph->tab[prs->end_index].list;

	while (adjs_of_end)
	{
		printf(" === adj : |%s| \n", prs->array_of_rooms[adjs_of_end->dst]);
		t_stack *adj;
		adj = prs->last_start;
		while (adj)
		{
			if (adj->room == adjs_of_end->dst || !adj->prev)
				break;
			adj = adj->prev;
		}
		// printf("%s %s, [%s], %d, \n", prs->array_of_rooms[adj->room], prs->array_of_rooms[adj->parent->room], prs->array_of_rooms[adj->predecessor->room], adj->len);
 printf("len = [%d]\n",  adj->len);
		// pred = adjs_of_end->dst;
		printf("{END}");
		// if (adj)
		// {
			while (adj->room != prs->start_index)
			{
				printf("%s|", prs->array_of_rooms[adj->room]);

					adj = adj->predecessor;
			}
		// }
		printf("{SART}\n\n");
		adjs_of_end = adjs_of_end->next;
	}
}

void ant_eater(t_parse *prs)
{
	bfs_init(prs);
	prs->there_is_intersection = FALSE;
	prs->visited = 1;

	push(prs, prs->start_index, prs->start_index);
	prs->iterator = prs->stack;
	prs->last_start = prs->stack;
	prs->discovered[prs->start_index] = prs->visited;
	while (shortest_path(prs, prs->start_index, prs->end_index))
	{
		// track_real_predecessors(prs);
	}
	printf("sortir\n");

	//breadth_first_search(prs, prs->start_index, prs->end_index);
	//prs->visited++;

	// print_stack(prs);
	// exiter

	// print_stack(prs);
	// exiter
	track_real_predecessors(prs);
}
