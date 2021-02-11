/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 08:26:36 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/14 16:30:48 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < ((int)ft_strlen(haystack)) - ((int)ft_strlen(needle)) + 1)
	{
		if (ft_strncmp((char *)haystack + i, needle, ft_strlen(needle)) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
