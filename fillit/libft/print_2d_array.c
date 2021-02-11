/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2d_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:22:47 by aybouras          #+#    #+#             */
/*   Updated: 2019/05/23 13:17:35 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_2d_array(char matrix[4][4])
{
	int row;
	int column;

	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			ft_putchar(matrix[row][column]);
			column++;
		}
		ft_putchar('\n');
		row++;
	}
}
