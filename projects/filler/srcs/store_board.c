/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:36:39 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/13 20:36:42 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		get_map_dimensions(t_filler *f, char *line)
{
	if (ft_strchr(line, ' '))
		f->map_rows = ft_atoi(ft_strchr(line, ' ') + 1);
	else
		return (manage_errors(f, 0, line, PARSE_CHCK));
	if (ft_strrchr(line, ' '))
		f->map_cols = ft_atoi(ft_strrchr(line, ' ') + 1);
	else
		return (manage_errors(f, 0, line, PARSE_CHCK));
	if (f->map_rows <= 0 || f->map_cols <= 0)
		return (manage_errors(f, 0, line, PARSE_CHCK));
	f->map_dim_is_set = TRUE;
	return (0);
}

int		allocate_board(t_filler *f)
{
	ft_strdel(&f->line);
	f->board_char = (char **)ft_memalloc(f->map_rows * sizeof(char *));
	f->board_int = (int **)ft_memalloc(f->map_rows * sizeof(int *));
	if (manage_errors(f, f->ret, f->line, BOARD_MALLOC_CHCK))
		return (1);
	return (0);
}

/*
** if ft_strstr(f->line, "Piece")
** to prevent a conflict between rows value and what GNL actualy reads
** (rows max > actual read)
*/

int		create_board(t_filler *f)
{
	int row;

	f->line = NULL;
	f->ret = get_next_line(0, &f->line, 1);
	if (map_error_check(f))
		return (1);
	if (allocate_board(f))
		return (1);
	row = -1;
	while (++row < f->map_rows && (f->ret = get_next_line(0, &f->line, 1)) > 0)
	{
		if (f->line[3] == ' ' && (int)ft_strlen(f->line) == f->map_cols + 4
			&& !ft_strstr(f->line, "Piece"))
		{
			f->board_char[row] = ft_strdup(f->line + 4);
			if (f->board_char[row] == NULL)
				return (map_storage_failure(f, row));
			ft_strdel(&f->line);
		}
		else
			return (map_storage_failure(f, row));
		f->board_int[row] = (int *)ft_memalloc(f->map_cols * sizeof(int));
		ft_char2int(f, row);
	}
	return (manage_errors(f, f->ret, f->line, GNL_RET_CHCK));
}

int		update_board(t_filler *f)
{
	int		row;

	f->line = NULL;
	f->ret = 0;
	f->ret = get_next_line(0, &f->line, 1);
	if (map_error_check(f))
		return (1);
	ft_strdel(&f->line);
	row = -1;
	while (++row < f->map_rows && (f->ret = get_next_line(0, &f->line, 1)) > 0)
	{
		if (f->line[3] == ' ' && f->line + 4
			&& (int)ft_strlen(f->line) == f->map_cols + 4)
		{
			ft_strcpy(f->board_char[row], f->line + 4);
			ft_strdel(&f->line);
		}
		else
			return (map_update_failure(f));
		ft_char2int(f, row);
	}
	return (manage_errors(f, f->ret, f->line, GNL_RET_CHCK));
}

int		store_board(t_filler *f)
{
	if (!f->board_is_allocated)
	{
		if (create_board(f))
			return (1);
		f->board_is_allocated = TRUE;
		heat_map(f);
	}
	else
	{
		if (update_board(f))
			return (1);
		heat_map(f);
	}
	return (0);
}
