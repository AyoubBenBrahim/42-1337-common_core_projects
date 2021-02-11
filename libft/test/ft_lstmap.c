/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:56:37 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/20 15:16:53 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *start;

	if (lst == NULL)
		return (NULL);
	fresh = f(lst);
	if (fresh == NULL)
		return (NULL);
	start = fresh;
	ft_lstprint(fresh);//-------
	while (lst->next)
	{
		//if (!(fresh->next = f(lst->next)))
		ft_lstprint(fresh);//-------
		if (fresh->next == NULL)	
		{
			ft_lstdel(&start, &ft_del);
			return (NULL);
		}
		fresh = fresh->next;
		lst = lst->next;
	}
	return (start);
}

t_list 	*f(t_list *list)
{
	size_t	i;

	i = 0;
	t_list  *new = ft_lstnew(list->content, list->content_size);
	while (i < new->content_size)
	{
		((char *)new->content)[i]++;
		i++;
	}
	return (new);
}

int main()
{
	t_list      *tab0;
	t_list      *tab1;
	t_list      *tab2;

	tab0 = ft_lstnew("aaaa", 4);
	tab1 = ft_lstnew("bbbb", 4);
	tab2 = ft_lstnew("1234", 4);

	tab0->next = tab1;
	tab1->next = tab2;
	tab2->next = NULL;


	t_list	*fresh;
	fresh = ft_lstmap(tab0, &f);
	ft_lstprint(fresh);
}
