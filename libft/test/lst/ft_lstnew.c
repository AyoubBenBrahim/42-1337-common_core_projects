/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:33:51 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/21 13:32:07 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_list;

	new_list = malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->content = malloc(content_size);
	if (new_list->content == NULL)
		return (NULL);
	new_list->next = NULL;
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
		return (new_list);
	}
	new_list->content_size = content_size;
	ft_memcpy(new_list->content, content, content_size);
	return (new_list);
}

/* int main()
{
	t_list *tmp;

	tmp = ft_lstnew("bou3aza", 8);
	tmp->next = ft_lstnew("khou_bou3aza", 12);
	tmp->next->next = ft_lstnew("khou_khou_bou3aza", 17);
	tmp->next->next->next = NULL;
	while(tmp)
	{
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
	return (0);
}*/
