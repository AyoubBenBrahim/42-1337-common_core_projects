/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swpcntlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:38:20 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/27 11:13:54 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swpcntlst(t_list *l1, t_list *l2)
{
	void	*tmp;
	size_t	t;

	tmp = l1->content;
	t = l1->content_size;
	l1->content = l2->content;
	l1->content_size = l2->content_size;
	l2->content = tmp;
	l2->content_size = t;
}
