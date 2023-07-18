/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:40:16 by ayb*****          #+#    #+#             */
/*   Updated: 2019/05/28 17:53:07 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_board(int map_max)
{
	char	**map;
	int		row;

	map = (char **)malloc(map_max * sizeof(char *));
	row = -1;
	while (++row < map_max)
	{
		map[row] = (char *)malloc(map_max * sizeof(char));
		ft_memset(map[row], '.', map_max);
	}
	return (map);
}
