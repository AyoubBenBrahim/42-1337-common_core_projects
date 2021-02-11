/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:58:27 by aybouras          #+#    #+#             */
/*   Updated: 2019/05/31 15:48:21 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_empty(char matrix[4][4])
{
	int row;
	int column;

	row = -1;
	while (++row < 4)
	{
		column = -1;
		while (++column < 4)
			matrix[row][column] = 0;
	}
}

int			check_sides(char matrix[4][4], int row, int column, int counter)
{
	if (matrix[row][column + 1] == '#' && column != 3)
		counter++;
	if (matrix[row][column - 1] == '#' && column != 0)
		counter++;
	if (matrix[row - 1][column] == '#' && row != 0)
		counter++;
	if (matrix[row + 1][column] == '#' && row != 3)
		counter++;
	return (counter);
}

t_list2		*ft_stock(char matrix[4][4], t_list2 *list)
{
	char id;

	rearrange_tetriminos(matrix);
	id = 'A';
	if (list == NULL)
		list = ft_lstnew2(matrix, id);
	else
	{
		id = id + ft_lstlen(list);
		add_at_end(list, ft_lstnew2(matrix, id));
	}
	ft_empty(matrix);
	return (list);
}

t_list2		*validate_tetriminos(char matrix[4][4])
{
	static t_list2	*list = NULL;
	int				row;
	int				column;
	int				counter;
	int				hash_counter;

	row = -1;
	hash_counter = 0;
	counter = 0;
	while (++row < 4)
	{
		column = -1;
		while (++column < 4)
			if (matrix[row][column] == '#'
					&& (counter = check_sides(matrix, row, column, counter)))
				hash_counter++;
			else if (matrix[row][column] == '.')
				continue;
			else
				return (NULL);
	}
	if (counter < 6 && hash_counter != 4)
		ft_empty(matrix);
	return ((counter >= 6 && hash_counter == 4) ?
			(list = ft_stock(matrix, list)) : NULL);
}

t_list2		*validate_file(char *line, int fd)
{
	t_list2	*list;
	int		line_feed;
	char	matrix[4][4];
	int		row;
	int		column;

	line_feed = 0;
	row = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		column = -1;
		if ((row == 0 && *line == '\0') || (ft_strlen(line) != 4 && *line)
				|| (row == 4 && *line))
			return (NULL);
		while (line[++column])
			matrix[row][column] = line[column];
		if (row++ && !*line && ++line_feed)
			row = 0;
		free(line);
		if (matrix[3][3] && (list = validate_tetriminos(matrix)) == NULL)
			return (NULL);
	}
	return ((ft_lstlen(list) == line_feed ||
				(ft_lstlen(list) < 1 || ft_lstlen(list) > 26)) ? NULL : list);
}
