/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:08:03 by ayb*****          #+#    #+#             */
/*   Updated: 2020/01/25 20:17:18 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H
# define BUFF_SIZE 2

# include "../libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define ME					f->me
# define VM					f->enemy
# define READ_LINE			get_next_line(0, &line, 1)
# define FREE_LINE			ft_strdel(&line)
# define GNL_RET_CHCK		0
# define BOARD_MALLOC_CHCK	1
# define PIECE_MALLOC_CHCK	2
# define PARSE_CHCK			3
# define TO_LOWER(x)		(x | ' ')
# define IS_ME(x, y)		(x == y || TO_LOWER(x) == y)
# define IS_ENEMY(x, y)		(x == y || TO_LOWER(x) == y)
# define EMPTY				-2
# define NORTH				f->board_int[r - 1][c]
# define SOUTH				f->board_int[r + 1][c]
# define EAST				f->board_int[r][c + 1]
# define WEST				f->board_int[r][c - 1]
# define NORTH_EAST			f->board_int[r - 1][c + 1]
# define NORTH_WEST			f->board_int[r - 1][c - 1]
# define SOUTH_EAST			f->board_int[r + 1][c + 1]
# define SOUTH_WEST			f->board_int[r + 1][c - 1]

typedef enum				e_boolean
{
	FALSE,
	TRUE,
}							t_boolean;

typedef struct				s_store
{
	int						row;
	int						col;
	int						score;
}							t_store;

typedef struct				s_filler
{
	int						map_rows;
	int						map_cols;
	char					**board_char;
	int						**board_int;
	t_boolean				board_is_allocated;
	t_boolean				map_dim_is_set;
	t_boolean				diagonal;
	char					me;
	char					enemy;
	t_store					tstore;
	char					*line;
	char					*linee;
	int						ret;
	int						piece_rows;
	int						piece_cols;
	char					**piece;
	int						total_stars;
	int						pstart_row;
	int						pend_row;
	int						pstart_col;
	int						pend_col;
	int						m_r;
	int						m_c;
	int						p_r;
	int						p_c;
	int						matched;
	int						score;
	int						mr;
	int						mc;
	int						pr;
	int						pc;
	int						ligne;
	int						colone;
	int						real_r;
	int						real_c;
	int						star_count;
	int						i;
}							t_filler;

int							get_next_line(const int fd, char **line, int flag);
int							get_map_dimensions(t_filler *f, char *line);
void						free_piece(t_filler *f);
void						free_board(t_filler *filler);
int							manage_errors(t_filler *f, int gnl_return,
							char *line, int flag);
void						ft_char2int(t_filler *filler, int row);
void						heat_map(t_filler *filler);
void						fill_sides(t_filler *f, int row, int col, int nbr);
int							check_if_placeable(t_filler *f);
int							store_piece(t_filler *f);
int							store_board(t_filler *f);
void						trim_piece(t_filler *f);
void						set_score(t_filler *f);
int							is_placeable(t_filler *f);
int							map_storage_failure(t_filler *f, int row);
int							map_update_failure(t_filler *f);
int							map_error_check(t_filler *f);

#endif
