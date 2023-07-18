/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:08:50 by ayb*****          #+#    #+#             */
/*   Updated: 2020/01/25 20:17:41 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	switch_strategy(t_filler *f)
{
	int row;
	int col;

	row = -1;
	while (++row < 5)
	{
		col = -1;
		while (++col < f->map_cols)
		{
			if (IS_ME(f->board_char[row][col], ME))
			{
				f->diagonal = FALSE;
				break ;
			}
		}
	}
}

void	top_down_model(t_filler *f)
{
	int row;
	int col;

	if (f->map_rows <= 20 && f->me == 'O')
	{
		switch_strategy(f);
		if (f->diagonal)
		{
			row = 0;
			col = 8;
			while (row <= 7)
			{
				f->board_int[row][col] = 0;
				row++;
			}
		}
	}
}

void	bottom_up_model(t_filler *f)
{
	if (f->map_rows <= 20 && f->me == 'X')
	{
		switch_strategy(f);
		if (f->diagonal)
		{
			f->i = 0;
			while (f->i <= 7)
			{
				f->board_int[f->i][f->i + 7] = 0;
				f->i++;
			}
		}
	}
}

void	heat_map(t_filler *f)
{
	int row;
	int col;
	int find;

	top_down_model(f);
	bottom_up_model(f);
	row = -1;
	find = 0;
	while (find < f->map_rows + f->map_cols)
	{
		while (++row < f->map_rows)
		{
			col = -1;
			while (++col < f->map_cols)
			{
				if (f->board_int[row][col] == find)
					fill_sides(f, row, col, find + 1);
			}
		}
		row = -1;
		find++;
	}
}
