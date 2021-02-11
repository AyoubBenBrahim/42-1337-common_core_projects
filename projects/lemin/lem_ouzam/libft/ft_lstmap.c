/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:47:51 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/23 09:29:30 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_makel(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;

	if (!(res = malloc(sizeof(t_list))))
		return (NULL);
	res = (*f)(lst);
	return (res);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*resr;

	res = ft_makel(lst, f);
	resr = res;
	while (lst->next != NULL)
	{
		resr->next = ft_makel(lst->next, f);
		resr = resr->next;
		lst = lst->next;
	}
	return (res);
}
