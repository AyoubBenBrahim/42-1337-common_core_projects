/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisempty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:46:07 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/18 19:32:47 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int		ft_lstisempty(t_list *head)
{
	return ((head == NULL) ? 1 : 0);
}
/*
int main()
{
	t_list      *tab0;
//	char        str2 [] = "123";

	tab0 = NULL;
	//tab0 = ft_lstnew(str2, 3);
	int i = ft_lstisempty(tab0);
	printf("%d",i);
}
*/
