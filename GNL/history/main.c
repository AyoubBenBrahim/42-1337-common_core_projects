/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:47:55 by ayb*****          #+#    #+#             */
/*   Updated: 2019/05/05 17:16:44 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int		main(int arc, char **arv)
{
	int		fd,fd2,fd3;
	char	*line;
	int		ret;

	fd = open(arv[1], O_RDONLY);
	fd2 = open(arv[2], O_RDONLY);
	fd3 = open(arv[3], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}

/*	get_next_line(fd, &line);
	printf("%s\n\n", line);
	free(line);

	get_next_line(fd2, &line);
	printf("%s\n\n", line);
	free(line);

	get_next_line(fd3, &line);
	printf("%s\n\n", line);
	free(line);
*/

}
