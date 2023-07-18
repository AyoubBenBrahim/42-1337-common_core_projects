/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:29:33 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/27 19:12:25 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFF_SIZE 10

int get_index_of_line_feed(char buff[BUFF_SIZE])
{
	int i;
	int index;
	
	i = 0;
	index = -1;
	while (i < BUFF_SIZE)
	{
		if (buff[i] == '\n')
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
	static char buffer[BUFF_SIZE + 1];
	static char the_rest[BUFF_SIZE];
	int res;
	while ((res = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		int i;
		int j;
		int index;
	
		if (the_rest[0])
			*line = ft_strjoin(the_rest, buffer);
		printf("ligne %s\n", *line);
	
		i = 0;
		index = get_index_of_line_feed(buffer);
		j = index;
		if (index++ != -1)
		{
			while (index < BUFF_SIZE)
				the_rest[i++] = buffer[index++];
			printf("the rest %s\n", the_rest);

			//*line = (char *)malloc(sizeof(char) * j);
			*line = ft_strsub(buffer, 0, j);
		}
		else // if \n not found
		{
			*line = ft_strjoin(*line, buffer);
		}
	}
	return (0);
}

int main(void)
{
	int fd = open("file", O_RDONLY);
	char *line;
	//while (get_next_line(fd, line) == 1)
	get_next_line(fd, &line);
	printf("line %s\n",line);
}
