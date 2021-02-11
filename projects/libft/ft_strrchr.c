/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:49:59 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/03 21:16:24 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				size;

	size = ft_strlen(s);
	i = size;
	while (i >= 0)
	{
		if (s[i] != (char)c)
			i--;
		else
			return ((char *)(s + i));
	}
	return (0);
}
