/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_placeable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:31:48 by aybouras          #+#    #+#             */
/*   Updated: 2019/05/30 18:47:06 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		on_board(char **map, t_list2 *list, int *coordinates, int map_max)
{
	int ligne;
	int col;
	int c;
	int r;

	ligne = -1;
	r = coordinates[0];
	while (r <= coordinates[0] + 3 && ++ligne < 4 && r < map_max)
	{
		col = -1;
		c = coordinates[1];
		if (!ft_isalpha(list->tab[0][0]))
			c = coordinates[1] - 1;
		if (!ft_isalpha(list->tab[0][0]) && !ft_isalpha(list->tab[0][1]))
			c = coordinates[1] - 2;
		while (c <= coordinates[1] + 3 && ++col < 4 && c < map_max)
		{
			if (ft_isalpha(list->tab[ligne][col]))
				map[r][c] = list->tab[ligne][col];
			c++;
		}
		r++;
	}
	return (1);
}

int		is_placeable(char **map, t_list2 *list, int *coordinates, int map_max)
{
	int ligne;
	int col;
	int c;
	int r;
	int placeable;

	ligne = -1;
	r = coordinates[0] - 1;
	placeable = 0;
	while (++r <= coordinates[0] + 3 && ++ligne < 4 && r < map_max)
	{
		col = -1;
		c = coordinates[1];
		if (!ft_isalpha(list->tab[0][0]))
			c = coordinates[1] - 1;
		if (!ft_isalpha(list->tab[0][0]) && !ft_isalpha(list->tab[0][1]))
			c = coordinates[1] - 2;
		while (c <= coordinates[1] + 3 && ++col < 4 && c < map_max)
		{
			if (ft_isalpha(list->tab[ligne][col]) && map[r][c] == '.')
				placeable++;
			c++;
		}
	}
	return ((placeable == 4) ? on_board(map, list, coordinates, map_max) : 0);
}
