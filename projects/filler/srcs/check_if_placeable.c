/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_placeable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:30:26 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/25 20:17:32 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		free_before_last_put(t_filler *f)
{
	char *line;

	get_next_line(0, &line, 0);
	free_board(f);
	free_piece(f);
	ft_putnbr(f->tstore.row);
	ft_putchar(' ');
	ft_putnbr(f->tstore.col);
	ft_putchar('\n');
	return (1);
}

int		send_coords_2vm(t_filler *f)
{
	if (f->tstore.row == INT_MAX)
		return (free_before_last_put(f));
	ft_putnbr(f->tstore.row);
	ft_putchar(' ');
	ft_putnbr(f->tstore.col);
	ft_putchar('\n');
	return (0);
}

int		iterat_map(t_filler *f)
{
	if (f->m_c >= f->map_cols)
		f->m_r += 1;
	while (f->m_r < f->map_rows)
	{
		if (f->m_c >= f->map_cols)
			f->m_c = 0;
		while (f->m_c < f->map_cols)
		{
			if (f->board_int[f->m_r][f->m_c] == -1)
			{
				f->m_c++;
				return (1);
			}
			f->m_c++;
		}
		f->m_r++;
	}
	return (0);
}

int		check_if_placeable(t_filler *f)
{
	f->tstore.row = INT_MAX;
	f->tstore.col = INT_MAX;
	f->tstore.score = INT_MAX;
	f->pstart_row = 0;
	f->pend_row = f->piece_rows - 1;
	f->pstart_col = 0;
	f->pend_col = f->piece_cols - 1;
	if (f->map_rows >= 100)
		trim_piece(f);
	f->p_r = f->pstart_row;
	while (f->p_r <= f->pend_row)
	{
		f->p_c = f->pstart_col;
		while (f->p_c <= f->pend_col)
		{
			f->m_r = 0;
			f->m_c = 0;
			while (iterat_map(f))
				is_placeable(f);
			f->p_c++;
		}
		f->p_r++;
	}
	return (send_coords_2vm(f));
}
