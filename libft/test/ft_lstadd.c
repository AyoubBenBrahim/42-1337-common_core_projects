/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:03:09 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/17 23:37:11 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

int main()
{
	t_list      *tab1;
	t_list      *tab2;
	char        str1 [] = "str1";
	char        str2 [] = "str2";

	tab1 = ft_lstnew(str1, 4);
	tab2 = ft_lstnew(str2, 4);

	tab1->next = tab2;
	tab2->next = NULL;

	t_list *tab0;
	char   str0[] = "str0";
	tab0 = ft_lstnew(str0, 4);

	ft_lstadd(&tab1, tab0);

	ft_lstprint(tab1);
}
