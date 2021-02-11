/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 00:29:41 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/20 12:50:40 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if (!(s == NULL || f == NULL))
	{
		i = 0;
		if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1))))
			return (0);
		while (i < ft_strlen(s))
		{
			str[i] = (f)(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
