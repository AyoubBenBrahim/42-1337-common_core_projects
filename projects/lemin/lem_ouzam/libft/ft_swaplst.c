/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaplst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:17:55 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/27 11:09:56 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swaplst(t_list **lst1, t_list **lst2)
{
	t_list *lst;

	lst = *lst1;
	*lst1 = *lst2;
	*lst2 = lst;
	lst = (*lst1)->next;
	(*lst1)->next = (*lst2)->next;
	(*lst2)->next = lst;
}
