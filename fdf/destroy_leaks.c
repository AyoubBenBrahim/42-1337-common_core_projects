/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_leaks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:09:26 by aybouras          #+#    #+#             */
/*   Updated: 2019/07/18 16:35:47 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_nodes(t_list2 **list)
{
	t_list2 *current;
	t_list2 *next;

	current = *list;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}

void	destroy_leaks(t_option *t_opt)
{
	free_nodes(&t_opt->head);
	if (t_opt)
	{
		free(t_opt);
		t_opt = NULL;
	}
}
