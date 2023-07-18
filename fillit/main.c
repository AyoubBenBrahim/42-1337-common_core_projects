/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:58:26 by ayb*****          #+#    #+#             */
/*   Updated: 2019/05/31 15:52:48 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int arc, char **arv)
{
	char	*line;
	t_list2	*list;
	int		fd1;
	int		fd2;

	if (arc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	line = NULL;
	list = NULL;
	fd1 = open(arv[1], O_RDONLY);
	if (!manage_errors(list, fd1, 0, 1))
		return (0);
	fd2 = open(arv[1], O_RDONLY);
	if (fd2 >= 0)
		list = validate_file(line, fd2);
	if (!manage_errors(list, 0, fd2, 2))
		return (0);
	fillit(list);
	return (0);
}
