/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_black_hole.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:01:13 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/25 20:17:45 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	free_board(t_filler *filler)
{
	int row;
	int rows;

	row = 0;
	rows = filler->map_rows;
	if (filler->board_char || filler->board_int)
	{
		while (row < rows)
		{
			if ((filler->board_char)[row])
				ft_strdel(&((filler->board_char)[row]));
			if ((filler->board_int)[row])
				ft_memdel((void **)&((filler->board_int)[row]));
			row++;
		}
		if (filler->board_char)
		{
			ft_memdel((void **)&filler->board_char);
		}
		if (filler->board_int)
			ft_memdel((void **)&(filler->board_int));
	}
}

void	free_piece(t_filler *f)
{
	int row;

	row = 0;
	if (f->piece)
	{
		while (row < f->piece_rows && f->piece[row])
		{
			ft_strdel(&f->piece[row]);
			row++;
		}
		ft_memdel((void **)&f->piece);
	}
}
