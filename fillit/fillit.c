/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:24:42 by aybouras          #+#    #+#             */
/*   Updated: 2019/05/30 17:15:25 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_tetrimino(int current_row, char id, char **map, int map_max)
{
	int row;
	int column;
	int counter;

	counter = 0;
	row = current_row;
	while (row <= map_max)
	{
		column = -1;
		while (++column < map_max)
		{
			if (map[row][column] == id)
			{
				map[row][column] = '.';
				counter++;
			}
			if (counter == 4)
				return ;
		}
		row++;
	}
}

int		ft_solving(t_list2 *list, char **map, int map_max)
{
	int coordinates[2];
	int row;
	int column;

	row = -1;
	if (!list)
		return (1);
	while (++row < map_max)
	{
		column = -1;
		while (++column < map_max)
		{
			coordinates[0] = row;
			coordinates[1] = column;
			if (is_placeable(map, list, coordinates, map_max))
			{
				if (ft_solving(list->next, map, map_max))
					return (1);
				else
					remove_tetrimino(coordinates[0], list->id, map, map_max);
			}
		}
	}
	return (0);
}

void	fillit(t_list2 *list)
{
	char	**map;
	int		map_max;

	map_max = 0;
	map_max = ft_sqrt(ft_lstlen(list) * 4);
	map = NULL;
	map = create_board(map_max);
	while (!ft_solving(list, map, map_max))
	{
		free_map(&map, map_max);
		map = create_board(++map_max);
	}
	print_2p(map, map_max);
	free_map(&map, map_max);
	free_list(&list);
}
