/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:29:33 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/28 11:05:24 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFF_SIZE 10

char **store_file(int fd, int fdd)
 {
 	char buffer[BUFF_SIZE + 1];
 	char **tab;
 	char *file;
	int res;

	file = "";
	while ((res = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[res] = '\0';
		file = ft_strjoin(file, buffer);
		fdd = 0;
	}
		tab = ft_strsplit(file,'\n');
	return (tab);
 }

int get_next_line(const int fd, char **line)
{
	static int fdd;
	static int lenght;
	static char **tab;
	static int i;

	if (fdd != -2)
	{
		tab = store_file(fd, fdd);

		i = 0;
		
		while (tab[i])
		{
			lenght++;
			i++;
		}
		i = 0;
		fdd = -2;
	}

	if (i < lenght)
	{
		*line = tab[i];
		i++;
		return (1);
	}
	*line = NULL;
	return (0);
}

int main(void)
{
	int fd = open("file", O_RDONLY);
	char *line;
	int res;

	while (get_next_line(fd, &line))
		printf("%s\n",line);
}
