/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:49:10 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/19 18:47:43 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	f;
	void	*str;

	f = 0;
	if (!(str = (void *)malloc(sizeof(*str) * size)))
		return (0);
	while (f < size)
	{
		((char *)str)[f] = 0;
		f++;
	}
	return (str);
}
