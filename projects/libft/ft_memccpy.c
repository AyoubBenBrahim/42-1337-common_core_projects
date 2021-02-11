/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 20:29:32 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/19 18:54:03 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	tmp_src = (unsigned char*)src;
	tmp_dst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		if (tmp_src[i] != (unsigned char)c)
			tmp_dst[i] = tmp_src[i];
		else
		{
			tmp_dst[i] = tmp_src[i];
			return (&tmp_dst[i + 1]);
		}
		i++;
	}
	return (0);
}
