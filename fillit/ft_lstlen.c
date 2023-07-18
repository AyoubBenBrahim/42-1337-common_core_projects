/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:32:21 by ayb*****          #+#    #+#             */
/*   Updated: 2019/05/30 18:38:44 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_lstlen(t_list2 *head)
{
	t_list2	*temp;
	int		counter;

	temp = head;
	counter = 0;
	while (temp)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
}
