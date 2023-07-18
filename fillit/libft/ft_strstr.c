/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:30:24 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/03 14:30:42 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	lenght;

	lenght = ft_strlen(needle);
	if (*needle == '\0')
		return ((char*)(haystack));
	while (*haystack)
	{
		if (ft_memcmp(haystack, needle, lenght) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
