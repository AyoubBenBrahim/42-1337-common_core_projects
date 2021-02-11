/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:39:58 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/17 20:00:03 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare(const char *s, const char *t, size_t i, size_t len)
{
	int j;

	j = 0;
	while (i < len && s[i] && t[j])
	{
		if (s[i] != t[j])
			return (0);
		i++;
		j++;
	}
	return (t[j] == '\0');
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (*needle == '\0')
		return ((char*)(haystack));
	while (haystack[i] != '\0' && i < len)
	{
		if ((haystack[i] == needle[0]) && compare(haystack, needle, i, len))
			return ((char*)(haystack + i));
		i++;
	}
	return (0);
}
