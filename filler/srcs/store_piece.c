/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:26:37 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/14 09:26:40 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		stars_count(char *line)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (line[i])
		if (line[i++] == '*')
			count++;
	return (count);
}

int		get_piece_dimensions(t_filler *f)
{
	char	*line;

	line = NULL;
	f->ret = 0;
	while ((f->ret = READ_LINE) > 0)
	{
		if (ft_strncmp(line, "Piece", 5) == 0)
		{
			if (ft_strchr(line, ' '))
				f->piece_rows = ft_atoi(ft_strchr(line, ' ') + 1);
			else
				return (manage_errors(f, f->ret, line, PARSE_CHCK));
			if (ft_strrchr(line, ' '))
				f->piece_cols = ft_atoi(ft_strrchr(line, ' ') + 1);
			else
				return (manage_errors(f, f->ret, line, PARSE_CHCK));
			FREE_LINE;
			return (0);
		}
		FREE_LINE;
	}
	FREE_LINE;
	return ((manage_errors(f, f->ret, line, GNL_RET_CHCK)));
}

int		piece_storage_failure(t_filler *f, int row, char *line)
{
	f->piece_rows = row;
	free_piece(f);
	free_board(f);
	return (ft_strdel(&line));
}

int		store_piece(t_filler *f)
{
	int		row;
	char	*line;

	line = NULL;
	f->ret = 0;
	row = -1;
	f->total_stars = 0;
	free_piece(f);
	if (get_piece_dimensions(f))
		return (0);
	f->piece = (char **)ft_memalloc(f->piece_rows * sizeof(char *));
	if (manage_errors(f, f->ret, line, PIECE_MALLOC_CHCK))
		return (1);
	while (++row < f->piece_rows && (f->ret = READ_LINE) > 0)
	{
		if (ft_strstr(line, "Plateau") || (int)ft_strlen(line) != f->piece_cols)
			return (piece_storage_failure(f, row, line));
		f->piece[row] = ft_strdup(line);
		if (f->piece[row] == NULL)
			return (piece_storage_failure(f, row, line));
		f->total_stars += stars_count(line);
		FREE_LINE;
	}
	return ((manage_errors(f, f->ret, line, GNL_RET_CHCK)));
}
