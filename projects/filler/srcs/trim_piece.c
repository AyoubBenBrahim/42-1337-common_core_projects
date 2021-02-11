/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:28:02 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/14 19:28:04 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	trim_piece(t_filler *f)
{
	f->ligne = -1;
	f->i = 0;
	while (++f->ligne < f->piece_rows)
	{
		f->colone = -1;
		while (++f->colone <= f->piece_cols)
		{
			if (f->piece[f->ligne][f->colone] == '*' && f->i == 0)
			{
				f->pstart_row = f->ligne;
				f->pstart_col = f->colone;
				f->pend_row = f->ligne;
				f->pend_col = f->colone;
				f->i = 1;
			}
			if (f->piece[f->ligne][f->colone] == '*'
				&& f->pstart_col >= f->colone)
				f->pstart_col = f->colone;
			if (f->piece[f->ligne][f->colone] == '*' && f->pend_row <= f->ligne)
				f->pend_row = f->ligne;
			if (f->piece[f->ligne][f->colone] == '*'
				&& f->pend_col <= f->colone)
				f->pend_col = f->colone;
		}
	}
}
