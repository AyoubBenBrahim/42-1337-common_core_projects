/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:18:35 by aybouras          #+#    #+#             */
/*   Updated: 2019/07/13 21:48:55 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_last_line(t_list2 **list1, t_option **opt)
{
	t_crd	coord;

	coord.color = (*list1)->color;
	if ((*opt)->keycod == RIGHT_BUTTON)
	{
		(*list1)->color += 11111111;
		coord.color = (*list1)->color;
	}
	coord.z1 = (*list1)->z * (*opt)->z;
	coord.z2 = (*list1)->next->z * (*opt)->z;
	coord.x1 = (*list1)->cart_x;
	coord.y1 = (*list1)->cart_y;
	coord.x2 = (*list1)->next->cart_x;
	coord.y2 = (*list1)->next->cart_y;
	draw_line(*opt, coord);
	(*list1) = (*list1)->next;
}

void		ft_draw_last_elem(t_list2 **list1, t_list2 **list2, t_option **opt)
{
	t_crd coord;

	coord.color = (*list1)->color;
	if ((*opt)->keycod == RIGHT_BUTTON)
	{
		(*list1)->color += 11111111;
		coord.color = (*list1)->color;
	}
	coord.z1 = (*list1)->z * (*opt)->z;
	coord.z2 = (*list2)->z * (*opt)->z;
	coord.x1 = (*list1)->cart_x;
	coord.y1 = (*list1)->cart_y;
	coord.x2 = (*list2)->cart_x;
	coord.y2 = (*list2)->cart_y;
	draw_line(*opt, coord);
	(*list1) = (*list1)->next;
	(*list2) = (*list2)->next;
}

void		ft_draw_middle(t_list2 **list1, t_list2 **list2, t_option **opt)
{
	t_crd	coord;

	coord.color = (*list1)->color;
	if ((*opt)->keycod == RIGHT_BUTTON)
	{
		(*list1)->color += 11111111;
		coord.color = (*list1)->color;
	}
	coord.z1 = (*list1)->z * (*opt)->z;
	coord.z2 = (*list1)->next->z * (*opt)->z;
	coord.x1 = (*list1)->cart_x;
	coord.y1 = (*list1)->cart_y;
	coord.x2 = (*list1)->next->cart_x;
	coord.y2 = (*list1)->next->cart_y;
	draw_line((*opt), coord);
	coord.z2 = (*list2)->z * (*opt)->z;
	coord.x2 = (*list2)->cart_x;
	coord.y2 = (*list2)->cart_y;
	draw_line(*opt, coord);
	(*list1) = (*list1)->next;
	(*list2) = (*list2)->next;
}

void		ft_jump_to_next_line(t_list2 **list2, int nbr_columns)
{
	while (*list2)
	{
		if ((*list2)->cart_x == nbr_columns)
		{
			(*list2) = (*list2)->next;
			break ;
		}
		(*list2) = (*list2)->next;
	}
}

void		draw(t_list2 *head, t_option *opt)
{
	t_list2	*list1;
	t_list2	*list2;
	int		nbr_columns;

	list1 = head;
	list2 = head;
	while (list1->next)
		list1 = list1->next;
	nbr_columns = list1->cart_x;
	list1 = head;
	ft_jump_to_next_line(&list2, nbr_columns);
	while (list1)
	{
		if (list1->cart_x == nbr_columns && list1->cart_y == head->count - 1)
			break ;
		if (!list1->next->cart_x)
			ft_draw_last_elem(&list1, &list2, &opt);
		else if (list1->cart_y == head->count - 1)
			ft_draw_last_line(&list1, &opt);
		else
			ft_draw_middle(&list1, &list2, &opt);
	}
}
