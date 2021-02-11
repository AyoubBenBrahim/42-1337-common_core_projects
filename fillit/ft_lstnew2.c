/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:33:20 by aybouras          #+#    #+#             */
/*   Updated: 2019/05/30 18:40:26 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list2		*ft_lstnew2(char matrix[4][4], char id)
{
	t_list2	*new_list;
	int		i;
	int		j;

	new_list = (t_list2 *)malloc(sizeof(t_list2));
	if (!new_list)
		return (NULL);
	new_list->id = id;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (matrix[i][j] == '#')
				new_list->tab[i][j] = id;
			else
				new_list->tab[i][j] = matrix[i][j];
	}
	new_list->next = NULL;
	return (new_list);
}
