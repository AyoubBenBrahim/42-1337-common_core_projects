/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:29:33 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/30 22:19:25 by ayb*****         ###   ########.fr       */
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
	res = 0;
	while (file[res])
	{	
		if ((    (file[res] == '\n') && file[res + 1] == '\n'  ) ||
	 ((file[res] == '\200') && file[res + 1] == '\n'  ))
		{	file[res + 1] = '\200';
		}
		res++;
	}
	if (file[0] == '\n')
		file[0] = '\200';
//printf(" file :%s", file);
	tab = ft_strsplit(file,'\n');

	res = 0;
	int k = 0;
	while (tab[res])
	{
		k = 0;	
		while (tab[res][k])
		{
			if (tab[res][k] == '\200')
				tab[res][k] = '*';
			k++;
		}
//printf("tab: %s\n", tab[res]);
		res++;
	}
	return (tab);
 }

int get_index_of_line_feed(char *str)
{
	int i;
	int index;
	
	i = 0;
	index = -1;
	while (str[i])
	{
		if (str[i] == '*')
		{
			index = i;
			break ;
		}
		i++;
	}
	return (index);
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
	//	printf("i befor if %d\n",i);
	//	printf("tab befor if %s\n",tab[i]);

		if(get_index_of_line_feed(tab[i]) != -1)
		{	
//			printf("print i %d\n",i);
			*line = "\0";
//			printf("line inside if %s\n",*line);
//			printf("tab inside if %s\n",tab[i]);
//			printf("strlen %zu\n",ft_strlen(tab[i]));
			tab[i] = ft_strsub(tab[i], 1, ft_strlen(tab[i]) - 1);
//			printf("tab after sub %s\n",tab[i]);
		}
		else
		{
			if (i == lenght - 1)
			{
				return (0);
			}
//			printf("i inside else %d\n",i);
//			printf("tab inside else %s\n",tab[i]);
			*line = tab[i];
			i++;
		}
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *line;
	int res;

	while (get_next_line(fd, &line))
	{	
		printf("%s\n",line);

		//printf("================\n");
	}
	//free(line);
}
