/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:35:10 by ayb*****          #+#    #+#             */
/*   Updated: 2020/01/25 20:17:34 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	fill_sides(t_filler *f, int r, int c, int nbr)
{
	if (r != 0 && c != 0 && (NORTH_WEST == EMPTY))
		NORTH_WEST = nbr;
	if (r != 0 && (NORTH == EMPTY))
		NORTH = nbr;
	if (r != 0 && c != f->map_cols - 1 && (NORTH_EAST == EMPTY))
		NORTH_EAST = nbr;
	if (c != 0 && (WEST == EMPTY))
		WEST = nbr;
	if (c != f->map_cols - 1 && (EAST == EMPTY))
		EAST = nbr;
	if (r != f->map_rows - 1 && c != 0 && (SOUTH_WEST == EMPTY))
		SOUTH_WEST = nbr;
	if (r != f->map_rows - 1 && (SOUTH == EMPTY))
		SOUTH = nbr;
	if (r != f->map_rows - 1 && c != f->map_cols - 1 && (SOUTH_EAST == EMPTY))
		SOUTH_EAST = nbr;
}
