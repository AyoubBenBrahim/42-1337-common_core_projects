/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:56:37 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/20 13:25:51 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *start;

	if (!lst)
		return (NULL);
	fresh = f(lst);
	if (!fresh)
		return (NULL);
	start = fresh;
	while (lst->next)
	{
		if (!(fresh->next = f(lst->next)))
		{
			ft_lstdel(&start, &ft_del);
			return (NULL);
		}
		fresh = fresh->next;
		lst = lst->next;
	}
	fresh->next = NULL;
	return (start);
}
