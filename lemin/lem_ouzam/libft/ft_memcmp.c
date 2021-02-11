/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 23:00:43 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/12 18:22:02 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1cp;
	unsigned char	*s2cp;

	if (n == 0)
		return (0);
	else
	{
		i = 0;
		s1cp = (unsigned char *)s1;
		s2cp = (unsigned char *)s2;
		while (i < n - 1 && s2cp[i] == s1cp[i])
		{
			i++;
		}
		return (s1cp[i] - s2cp[i]);
	}
}
