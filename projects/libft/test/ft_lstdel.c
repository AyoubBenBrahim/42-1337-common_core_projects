/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:58:48 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/20 14:15:31 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	while (*alst != NULL)
	{
		temp = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = temp;
	}
}

/*
int main()
{
	t_list      *tab1;
	t_list      *tab2;
	t_list      *tab3;

	tab1 = ft_lstnew("str1", 4);
	tab2 = ft_lstnew("str2", 4);
	tab3 = ft_lstnew("str3", 4);

	tab1->next = tab2;
	tab2->next = tab3;
	tab3->next = NULL;

	ft_lstdel(&tab1, &ft_del);
	ft_lstprint(tab1);
	ft_lstprint(tab2);
	ft_lstprint(tab3);
}
*/


