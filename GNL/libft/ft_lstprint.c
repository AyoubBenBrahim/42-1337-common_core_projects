/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:53:55 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/20 15:26:08 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstprint(t_list *head)
{
	t_list *temp;

	temp = head;
	write(1, "List is:\n", 9);
	if (!temp)
	{
		write(1, "NULL\n", 5);
		return ;
	}
	while (temp != NULL)
	{
		write(1, temp->content, temp->content_size);
		write(1, " ", 1);
		temp = temp->next;
	}
	write(1, "\n", 1);
}
