/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:36:19 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/20 15:00:28 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*pt;
	size_t	size;

	size = ft_strlen(s1);
	pt = (char *)malloc((sizeof(char) * size) + 1);
	if (pt == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		pt[i] = s1[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
