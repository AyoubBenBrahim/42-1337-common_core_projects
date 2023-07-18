/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:29:35 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/18 20:36:16 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsearch(t_list *head, void const *content)
{
	t_list *tmp;
	size_t i;
	size_t count;

	tmp = head;
	if (ft_lstisempty(head))
		return (NULL);
	while (tmp != NULL)
	{
		i = 0;
		count = 0;
		while (i < tmp->content_size || ((char *)content)[i])
		{
			if (((char *)tmp->content)[i] == ((char *)content)[i])
				count++;
			i++;
		}
		if (i == count)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
