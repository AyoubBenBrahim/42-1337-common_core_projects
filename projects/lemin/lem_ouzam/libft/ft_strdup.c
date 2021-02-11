/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 00:05:58 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/12 16:36:09 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	i;
	int		j;
	char	*rs;

	j = 0;
	i = ft_strlen(s1);
	if (!(rs = (char *)malloc(sizeof(*rs) * (i + 1))))
		return (0);
	while (s1[j])
	{
		rs[j] = s1[j];
		j++;
	}
	rs[i] = '\0';
	return (rs);
}
