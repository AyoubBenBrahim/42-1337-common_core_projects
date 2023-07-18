/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:43:19 by ayb*****          #+#    #+#             */
/*   Updated: 2019/01/30 06:51:10 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		size_of_params(int argc, char **argv)
{
	int i;
	int j;
	int size;

	i = 1;
	size = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			size++;
			j++;
		}
		i++;
	}
	return (size + 1);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*tab;

	i = 1;
	j = 0;
	k = 0;
	tab = (char *)malloc(sizeof(char) * size_of_params(argc, argv) + 1);
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			tab[k++] = argv[i][j++];
		}
		tab[k++] = '\n';
		j = 0;
		i++;
	}
	tab[k - 1] = '\0';
	return (tab);
}
