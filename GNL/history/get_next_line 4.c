/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:29:33 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/28 11:05:24 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFF_SIZE 10







int get_next_line(const int fd, char **line)
{
	static int fdd;
	char buffer[BUFF_SIZE + 1];
	char *file;
	int res;
	static int lenght;
	static char **tab;
	static int i;


	printf("fdd: %d\n",fdd);
	file = "";
	while ((res = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (fdd == -2)
			break ;
		lenght = 0;
		//if (file == NULL)
		//	file = "";
		buffer[res] = '\0';
		file = ft_strjoin(file, buffer);
		fdd = 0;
	}

	printf("befor if fdd: %d\n",fdd);

	if (fdd != -2)
	{
		tab = ft_strsplit(file,'\n');
		i = 0;
		while (tab[i])
		{
			lenght++;
			i++;
		}

		i = 0;
		fdd = -2;
	}
	int k = 0;
	while (tab[k])
	{
		printf("tab: %s\n",tab[k]);
		k++;
	}
	printf("lenght: %d\n",lenght);
	printf("i = %d\n",i);
	if (i < lenght)
	{
		//printf("tab: %s\n",tab[j]);
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

/*	res = get_next_line(fd, &line);
	printf("res1: %d\n", res);
	printf("line %s\n",line);
	printf("------\n");
	res = get_next_line(fd, &line);
	printf("res2: %d\n", res);
	printf("line %s\n",line);
	printf("------\n");
	res = get_next_line(fd, &line);
	printf("res2: %d\n", res);
	printf("line %s\n",line);
	printf("------\n");
	res = get_next_line(fd, &line);
	printf("res2: %d\n", res);
	printf("line %s\n",line);
*/

	while (get_next_line(fd, &line))
		printf("line is %s\n",line);
}
