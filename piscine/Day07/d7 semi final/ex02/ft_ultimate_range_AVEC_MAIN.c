/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:22:09 by ayb*****          #+#    #+#             */
/*   Updated: 2019/01/27 15:39:41 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int size;
	int * tab;

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

		/*
		   i = 0;
		   while (i < size)
		   {
		   printf("%d", tab[i]);
		   i++;
		   }
		   printf("\n");

*/
		return(size);
	}
	return (0);
}

int main()
{
	int *c;
	int a = 2;
	int b = 10;
	int x;
	x = ft_ultimate_range(&c,a,b);


	int	i = 0;
	while (i < x)
	{
		printf("%d", c[i]);
		i++;
	}
}
