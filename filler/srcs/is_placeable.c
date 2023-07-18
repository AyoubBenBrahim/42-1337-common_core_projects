/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_placeable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:15:46 by ayb*****          #+#    #+#             */
/*   Updated: 2020/01/25 20:17:43 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	initialize(t_filler *f)
{
	f->real_r = f->m_r - f->p_r;
	f->real_c = (f->m_c - f->p_c) - 1;
	f->matched = 0;
	f->score = 0;
	f->star_count = 0;
}

int		is_placeable(t_filler *f)
{
	initialize(f);
	f->pr = (f->real_r < 0) ? (f->real_r * -1) - 1 : -1;
	f->mr = (f->real_r < 0) ? -1 : f->real_r - 1;
	while (++f->pr < f->piece_rows && ++f->mr < f->map_rows)
	{
		f->pc = (f->real_c < 0) ? (f->real_c * -1) - 1 : -1;
		f->mc = (f->real_c < 0) ? -1 : f->real_c - 1;
		while (++f->pc < f->piece_cols && ++f->mc < f->map_cols)
		{
			if (f->piece[f->pr][f->pc] == '*')
				f->star_count++;
			f->score += f->board_int[f->mr][f->mc];
			if (IS_ME(f->board_char[f->mr][f->mc], f->me)
				&& f->piece[f->pr][f->pc] == '*')
				f->matched++;
			if (IS_ENEMY(f->board_char[f->mr][f->mc], f->enemy)
				&& f->piece[f->pr][f->pc] == '*')
				return (0);
		}
	}
	if (f->matched == 1 && (f->star_count == f->total_stars))
		set_score(f);
	return (1);
}
