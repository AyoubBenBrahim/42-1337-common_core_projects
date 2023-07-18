/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:49:39 by ayb*****          #+#    #+#             */
/*   Updated: 2019/05/30 11:14:43 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **matrix, int len)
{
	int row;
	int column;

	row = -1;
	while (++row < len)
	{
		column = -1;
		while (++column < len)
			ft_putchar(matrix[row][column]);
		ft_putchar('\n');
	}
}
