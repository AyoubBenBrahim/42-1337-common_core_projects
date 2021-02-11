/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:38:30 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/13 09:22:45 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	int		j;

	j = 0;
	k = ft_strlen(dst);
	i = ft_strlen(dst);
	if (i < size)
	{
		while (i + 1 < size && src[j])
		{
			dst[i++] = src[j++];
		}
		dst[i] = '\0';
		return (k + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
