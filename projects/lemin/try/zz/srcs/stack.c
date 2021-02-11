
#include "../inc/lem_in.h"

void	free_stack(t_parse *prs)
{
	t_stack *current;
	t_stack *next;

	// printf("FREE STACK\n");
	current = prs->stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = NULL;
		current = next;
   }
	prs->stack = NULL;
}

int		push(t_parse *prs, int room, int parent)
{
	t_stack		*new;
	t_stack		*tmp;

	new = NULL;
	if (!prs->stack)
	{
		if (!(prs->stack = (t_stack *)malloc(sizeof(t_stack))))
			return (0);
		prs->stack->room = room;
		prs->stack->next = NULL;
		prs->stack->len = 1;
		prs->stack->parent = prs->stack;
		prs->lstack = prs->stack;
		return (room);
	}
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	new->room = room;
	// prs->stack_len++;
	new->next = NULL;

	tmp = prs->stack;
	while(tmp)
	{
		if (tmp->room == parent)
			break ;
		tmp = tmp->next;
	}

	new->parent = tmp;
	if (!tmp)
		printf("PARENT of |%s| NULL\n", prs->array_of_rooms[new->room]);
	new->len = new->parent->len + 1;
	prs->lstack->next = new;
	prs->lstack = new;

	return (room);
}
