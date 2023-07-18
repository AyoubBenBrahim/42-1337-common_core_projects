/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char2int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:36:59 by ayb*****          #+#    #+#             */
/*   Updated: 2020/01/25 20:17:37 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	normal_heat_map(t_filler *f, int row)
{
	int col;

	col = -1;
	while (f->board_char[row][++col])
	{
		if (IS_ME(f->board_char[row][col], ME))
			f->board_int[row][col] = -1;
		else if (IS_ENEMY(f->board_char[row][col], VM))
			f->board_int[row][col] = 0;
		else
			f->board_int[row][col] = EMPTY;
	}
}

void	big_map(t_filler *f, int row)
{
	int col;

	col = -1;
	while (f->board_char[row][++col])
	{
		if (IS_ME(f->board_char[row][col], ME))
			f->board_int[row][col] = -1;
		else if (f->board_char[row][col] == TO_LOWER(VM))
			f->board_int[row][col] = 0;
		else
			f->board_int[row][col] = EMPTY;
	}
}

void	toward_up_right(t_filler *f, int row)
{
	int col;

	col = -1;
	while (f->board_char[row][++col])
	{
		if (IS_ME(f->board_char[row][col], ME))
			f->board_int[row][col] = -1;
		else
			f->board_int[row][col] = EMPTY;
	}
}

void	toward_up_left(t_filler *f, int row)
{
	int col;

	col = -1;
	while (f->board_char[row][++col])
	{
		if (IS_ME(f->board_char[row][col], ME))
			f->board_int[row][col] = -1;
		else if (f->board_char[row][col] == TO_LOWER(VM))
			f->board_int[row][col] = 0;
		else if (f->board_char[row][col] == '.')
			f->board_int[row][col] = EMPTY;
	}
}

void	ft_char2int(t_filler *f, int row)
{
	if (f->map_rows >= 100)
		big_map(f, row);
	else if (f->map_rows <= 20 && f->me == 'X')
	{
		if (row <= 4 && !f->diagonal)
			normal_heat_map(f, row);
		else
			toward_up_left(f, row);
	}
	else if (f->map_rows <= 20 && f->me == 'O')
	{
		if (!f->diagonal)
			normal_heat_map(f, row);
		else
			toward_up_right(f, row);
	}
	else
		normal_heat_map(f, row);
}
