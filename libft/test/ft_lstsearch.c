/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:29:35 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/18 19:57:57 by aybouras         ###   ########.fr       */
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
	while(tmp != NULL)
	{
		i = 0;
		count = 0;
		while (i < tmp->content_size || ((char *)content)[i])
		{
			if (((char *)tmp->content)[i] == ((char *)content)[i])
				count++;
			i++;
		}
		if(i == count)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return (NULL); 
}


int main()
{
	t_list      *tab0;
	t_list      *tab1;
	t_list      *tab2;

	tab0 = ft_lstnew("aaa1", 4);
	tab1 = ft_lstnew("abcd", 4);
	tab2 = ft_lstnew("1234", 4);

	tab0->next = tab1;
	tab1->next = tab2;
	tab2->next = NULL;


	t_list	*search;
	search = ft_lstsearch(tab0, "1234");
	if (search)
		write(1, search->content, search->content_size);
	else
		write(1, "NULL", 4);
}


