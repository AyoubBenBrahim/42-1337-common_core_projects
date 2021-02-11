/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:53:09 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/25 20:17:47 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
**	check GNL return
**	check if board is allocated
**	check if piece is allocated
**	check if the line was parsed well
*/

int		map_storage_failure(t_filler *f, int row)
{
	f->map_rows = row;
	free_board(f);
	return (ft_strdel(&f->line));
}

int		map_update_failure(t_filler *f)
{
	free_piece(f);
	free_board(f);
	return (ft_strdel(&f->line));
}

int		map_error_check(t_filler *f)
{
	if (manage_errors(f, f->ret, f->line, GNL_RET_CHCK))
		return (1);
	if (ft_strncmp(f->line, "    ", 4) != 0 || !is_number(f->line + 4))
		return (ft_strdel(&f->line));
	if (f->map_cols != (int)ft_strlen(f->line + 4))
		return (manage_errors(f, f->ret, f->line, PARSE_CHCK));
	return (0);
}

int		manage_errors(t_filler *f, int gnl_return, char *line, int flag)
{
	if (flag == GNL_RET_CHCK && gnl_return <= 0)
	{
		if (f->board_is_allocated)
			free_board(f);
		free_piece(f);
		return (ft_strdel(&line));
	}
	else if (flag == BOARD_MALLOC_CHCK && (!f->board_char || !f->board_int))
	{
		free_board(f);
		return (ft_strdel(&line));
	}
	else if (flag == PIECE_MALLOC_CHCK && !f->piece)
	{
		free_board(f);
		return (ft_strdel(&line));
	}
	else if (flag == PARSE_CHCK)
		return (ft_strdel(&line));
	return (0);
}
