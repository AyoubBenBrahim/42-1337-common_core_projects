/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 01:36:54 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/11/03 16:22:40 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	k = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s2) + j + 1))))
		return (0);
	while (i < j)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < k)
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
