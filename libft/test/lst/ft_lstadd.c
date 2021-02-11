/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:03:09 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/21 13:35:22 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}

/*int main()
{
	t_list *tmp;
	t_list *tmp2;

	tmp = ft_lstnew("hello", 5);
	tmp2 = ft_lstnew(" World", 6);
	ft_lstadd(&tmp, tmp2);
	ft_lstprint(tmp);

	return(0);
}*/
