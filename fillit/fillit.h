/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 15:59:54 by aybouras          #+#    #+#             */
/*   Updated: 2019/05/31 15:53:11 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include "libft/libft.h"

typedef struct		s_list2
{
	char			id;
	char			tab[4][4];
	struct s_list2	*next;
}					t_list2;

void				fillit(t_list2 *list);
t_list2				*ft_lstnew2(char matrix[4][4], char id);
int					ft_lstlen(t_list2 *head);
t_list2				*add_at_end(t_list2 *old, t_list2 *new);
void				print_map(char **matrix, int len);
void				free_list(t_list2 **alst);
t_list2				*ft_lstsearch(t_list2 *head, char id);
char				**create_board(int map_max);
void				free_map(char ***map, int map_max);
int					is_placeable(char **map, t_list2 *list,
								int *coordinates, int map_max);
t_list2				*validate_file(char *line, int fd);
void				rearrange_tetriminos(char matrix[4][4]);
int					manage_errors(t_list2 *list, int fd1, int fd2, int flag);
#endif
