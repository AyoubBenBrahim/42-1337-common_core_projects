/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:37:22 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:37:23 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_hold(t_hold **lst, t_hold **last, t_hold *new)
{
	if (*lst)
	{
		(*last)->next = new;
		*last = new;
	}
	else
	{
		*lst = new;
		*last = new;
	}
}

t_hold	*creat_hold(void *adr, t_mem *mem)
{
	t_hold *hold;

	hold = ft_malloc((sizeof(t_hold)), mem);
	hold->adr = adr;
	hold->next = NULL;
	return (hold);
}
