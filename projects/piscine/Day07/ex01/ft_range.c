/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:03:11 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/30 12:58:23 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int taille;
	int i;

	taille = max - min;
	if (taille <= 0)
	{
		return (0);
	}
	tab = (int *)malloc(sizeof(int) * taille);
	i = 0;
	while (min < max)
	{
		tab[i] = min++;
		i++;
	}
	return (tab);
}
