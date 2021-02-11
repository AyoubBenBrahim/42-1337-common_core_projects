/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:07:09 by ahel-men          #+#    #+#             */
/*   Updated: 2020/10/27 13:09:31 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		*ft_strdup_int(int *s1, int start, int size)
{
	int		i;
	int		*pt;

	if (!s1)
		return (0);
	if (!(pt = (int *)ft_memalloc(sizeof(int) * size)))
		return (0);
	i = 0;
	while (size--)
		pt[i++] = s1[start++];

	return (pt);
}
