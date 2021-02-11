
#include "../inc/lem_in.h"

void	free_stack(t_parse *prs)
{
	t_stack *current;
	t_stack *next;

	// printf("FREE STACK\n");
	current = (prs)->stack;
	while (current)
	{
		next = (current)->next;
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

		// prs->stack->room = -1;

		prs->stack->next = NULL;
		prs->stack_len = 1;
		prs->stack->len = 1;
		prs->stack->parent = prs->stack;
		prs->stack->predecessor = NULL;
		prs->stack->prev = NULL;
		prs->lstack = prs->stack;
		return (room);
	}
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	new->room = room;
	prs->stack_len++;
	new->next = NULL;

	// tmp = prs->stack;
	tmp = prs->last_start;
	while(tmp)
	{
		if (tmp->room == parent)
			break ;
		tmp = tmp->next;
	}

	new->parent = tmp;
	new->predecessor = tmp;
	if (new->room == prs->start_index)
		new->len = 1;
	else
		new->len = new->parent->len + 1;
	new->prev = prs->lstack;
	prs->lstack->next = new;
	prs->lstack = new;

	return (room);
}
