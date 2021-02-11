/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:58:48 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/26 14:59:25 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*pt;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	pt = (char *)malloc(sizeof(char) + i);
	i = 0;
	while (src[i] != '\0')
	{
		pt[i] = src[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
