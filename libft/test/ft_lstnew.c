/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:33:51 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/17 23:27:47 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

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
	memcpy(new_list->content, content, content_size);
	return (new_list);
}

/*
int main()
{
	t_list *new_list;
	t_list *temp;

	new_list = ft_lstnew("12x45", 3);
	temp = new_list;
	printf("List is: ");
	while (temp != NULL)
	{
		printf("%s ", temp->content);
		temp = temp->next;
	}
	printf("\n");

}
*/
