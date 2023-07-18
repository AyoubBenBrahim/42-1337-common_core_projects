/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:49:39 by ayb*****          #+#    #+#             */
/*   Updated: 2019/05/29 15:59:59 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_2p(char **matrix, int len)
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
