/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:07:36 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/25 20:17:36 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	ft_init(t_filler *f)
{
	f->me = 'X';
	f->enemy = 'O';
	f->board_is_allocated = FALSE;
	f->map_dim_is_set = FALSE;
	f->diagonal = TRUE;
	f->board_char = NULL;
	f->board_int = NULL;
	f->piece = NULL;
}

int		set_players(t_filler *f)
{
	char *line;

	f->i = 0;
	line = NULL;
	f->ret = 0;
	f->ret = READ_LINE;
	if (f->ret > 0 && ft_strstr(line, ".filler]")
		&& ft_strncmp(line, "$$$ exec p", 10) == 0
		&& (ft_strstr(line, "p1 : [") || ft_strstr(line, "p2 : [")))
	{
		if (ft_strstr(line, "p1"))
		{
			f->me = 'O';
			f->enemy = 'X';
		}
		FREE_LINE;
		return (0);
	}
	else
	{
		get_next_line(0, &line, 0);
		FREE_LINE;
		return (1);
	}
}

int		filler_loop(t_filler *f)
{
	char *line;

	line = NULL;
	while ((f->ret = READ_LINE) > 0)
	{
		if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			if (!f->map_dim_is_set)
			{
				if (get_map_dimensions(f, line))
					return (0);
			}
			FREE_LINE;
			if (store_board(f))
				return (0);
			if (store_piece(f))
				return (0);
			if (check_if_placeable(f))
				return (0);
		}
		FREE_LINE;
	}
	return ((manage_errors(f, f->ret, line, GNL_RET_CHCK)));
}

int		main(void)
{
	t_filler f;

	ft_memset((void *)&f, 0, sizeof(t_filler));
	ft_init(&f);
	if (set_players(&f))
		return (1);
	while (1)
		return (filler_loop(&f));
	return (0);
}
