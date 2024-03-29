/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:44:17 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/20 14:15:05 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

/*
int main()
{
	t_list		*tab1;
	t_list		*tab2;
	t_list      *tab3;

	tab1 = ft_lstnew("str1", 4);
	tab2 = ft_lstnew("str2", 4);
	tab3 = ft_lstnew("str3", 4);

	tab1->next = tab2;
	tab2->next = tab3;
	tab3->next = NULL;

	ft_lstdelone(&tab1, &ft_del);
	ft_lstprint(tab1);
	ft_lstprint(tab2);
	ft_lstprint(tab3);
}
*/
