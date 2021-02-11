/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:37:19 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/27 12:13:59 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src < dst)
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	else
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	return (dst);
}
