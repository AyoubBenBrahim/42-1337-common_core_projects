/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:29:33 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/27 16:30:57 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFF_SIZE 10

static char buffer[BUFF_SIZE + 1];
static char store_the_rest[BUFF_SIZE];
static  char *tab;

int get_index_of_line_feed()
{
	return (0);
}

char	*check_for_line_feed(char lin[BUFF_SIZE])
{
	int i;
	int index;
//	i = 0;
//	while (i < BUFF_SIZE)
//			printf(">%c",lin[i++]);
	
	if (tab == NULL)
		tab = "";
	tab = ft_strjoin(tab ,lin);
	printf("tab %s\n", tab);
	i = 0;
	index = -1;
	while (i < BUFF_SIZE)
	{
		if (lin[i] == '\n')
		{
			index = i;
			break ;
		}
		i++;
	}
	i = 0;
	int j = index;
	if (index++ != -1)
	{
		while (index < BUFF_SIZE)
		//tab[i++] = lin[index++];	
		store_the_rest[i++] = lin[index++];
	}
	printf("the rest %s\n",store_the_rest);
	//printf("the rest %s\n", tab);
	
	char *t = (char *)malloc(sizeof(char) * j);
	i = 0;
	while (i < j)
	{	
		t[i] = lin[i];
		i++;
	}
	return (t);
}

int get_next_line(const int fd, char **line)
{
	int res = read(fd, buffer, BUFF_SIZE);
	buffer[BUFF_SIZE] = '\0';
	//*line = buffer;
	//printf("** %s\n", buffer + 1);
	*line = check_for_line_feed(buffer);
	return (res);
}

int main(void)
{
	int fd = open("file", O_RDONLY);
	char **line;
	int i = 0;
	//while (get_next_line(fd, line) == 1)
	get_next_line(fd, line);
	printf("line %s\n",*line);
}
