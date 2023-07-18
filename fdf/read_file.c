/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:34:48 by ahel-men          #+#    #+#             */
/*   Updated: 2019/07/18 22:04:48 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

void	delete_last(t_list2 **head)
{
	t_list2 *temp;
	t_list2 *prev;

	if (!head)
		return ;
	temp = *head;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	if (prev->next)
		free(prev->next);
	prev->next = NULL;
}

t_list2	*read_file(int fd, t_option *option)
{
	t_list2	*head;
	t_list2 *tmp;
	char	*line;
	int		ret;

	option->count = 0;
	if (!(head = (t_list2 *)ft_memalloc(sizeof(t_list2))))
		return (NULL);
	tmp = head;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(ft_parse(line, &tmp, option)))
		{
			destroy_leaks(option);
			return (NULL);
		}
		option->count++;
		free(line);
	}
	delete_last(&head);
	head->count = option->count;
	draw(head, option);
	return (head);
}
