/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:22:09 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/30 06:50:05 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int size;
	int *tab;

	size = max - min;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	tab = NULL;
	tab = (int *)malloc(sizeof(int) * size);
	i = 0;
	if (tab != NULL)
	{
		while (min < max)
		{
			tab[i] = min++;
			i++;
		}
		*range = tab;
		return (size);
	}
	return (0);
}
