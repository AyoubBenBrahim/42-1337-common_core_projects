/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:23:29 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/17 23:43:41 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *ls;

	ls = lst;
	while (ls)
	{
		f(ls);
		ls = ls->next;
	}
}

void    f(t_list *liste)
{
	int	i;

	i = 0;
	while (i < liste->content_size)
	{
		((char *)liste->content)[i]++;
		i++;
	}
}

int main()
{
	t_list      *tab0;
	t_list      *tab1;
	t_list      *tab2;
	char        str0 [] = "0000";
	char        str1 [] = "1111";
	char        str2 [] = "2222";

	tab0 = ft_lstnew(str0, 4);
	tab1 = ft_lstnew(str1, 4);
	tab2 = ft_lstnew(str2, 4);

	tab0->next = tab1;
	tab1->next = tab2;
	tab2->next = NULL;

	ft_lstiter(tab0, &f);
	ft_lstprint(tab0);
}
