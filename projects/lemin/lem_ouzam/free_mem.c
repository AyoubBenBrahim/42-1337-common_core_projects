/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:34:29 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:34:31 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(t_mem *mem)
{
	ft_putstr("Error\n");
	free_mem(mem);
}

void	free_mem(t_mem *mem)
{
	t_hold	*hold;

	while (mem->hld)
	{
		hold = mem->hld;
		mem->hld = mem->hld->next;
		free(hold->adr);
		free(hold);
	}
	while (mem->line)
	{
		hold = mem->line;
		mem->line = mem->line->next;
		free(hold->adr);
		free(hold);
	}
	exit(0);
}
