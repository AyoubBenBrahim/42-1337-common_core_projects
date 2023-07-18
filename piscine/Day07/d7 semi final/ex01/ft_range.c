/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:03:11 by ayb*****          #+#    #+#             */
/*   Updated: 2019/01/26 21:45:11 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int taille;
	int i;

	taille = max - min;
	tab = (int *)malloc(sizeof(int) * taille);
	i = 0;
	while (min < max)
	{
		tab[i] = min++;
		i++;
	}
	return (tab);
}

int main()
{
	int *tab;
	tab	= ft_range(5,10);
	int i = 0;
	while (i < 5)
	{
		printf("%d",tab[i]);
		i++;
	}
	return 0;
}
