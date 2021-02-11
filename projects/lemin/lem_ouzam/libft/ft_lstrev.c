/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:08:05 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/26 14:28:53 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list *lst;
	t_list *new;

	lst = NULL;
	while (*alst != NULL)
	{
		new = (*alst)->next;
		(*alst)->next = lst;
		lst = *(alst);
		*alst = new;
	}
}
