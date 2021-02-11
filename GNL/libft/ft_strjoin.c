/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:48:28 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/17 21:10:44 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*joined;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joined == NULL)
		return (NULL);
	while (*s1)
	{
		joined[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		joined[i] = *s2;
		s2++;
		i++;
	}
	joined[i] = '\0';
	return (joined);
}
