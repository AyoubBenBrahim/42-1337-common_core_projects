/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rearrange_tetriminos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 13:04:32 by aybouras          #+#    #+#             */
/*   Updated: 2019/05/30 18:57:34 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int			to_the_top(char matrix[4][4])
{
	int		row;
	int		column;

	column = 0;
	row = 1;
	while (column < 4)
	{
		if (matrix[0][column] == '#')
			return (0);
		column++;
	}
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			matrix[row - 1][column] = matrix[row][column];
			matrix[row][column] = '.';
			column++;
		}
		row++;
	}
	return (1);
}

int			to_the_left(char matrix[4][4])
{
	int		row;
	int		column;

	column = 1;
	row = 0;
	while (row < 4)
	{
		if (matrix[row][0] == '#')
			return (0);
		row++;
	}
	row = 0;
	while (row < 4)
	{
		column = 1;
		while (column < 4)
		{
			matrix[row][column - 1] = matrix[row][column];
			matrix[row][column] = '.';
			column++;
		}
		row++;
	}
	return (1);
}

void		rearrange_tetriminos(char matrix[4][4])
{
	while (to_the_top(matrix))
		continue;
	while (to_the_left(matrix))
		continue;
}
