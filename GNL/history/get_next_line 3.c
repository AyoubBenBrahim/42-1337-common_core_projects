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
	char buffer[BUFF_SIZE + 1];
	static char *file;
	int res;
	while ((res = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (file == NULL)
			file = "";
		buffer[res] = '\0';
	//	printf("buffer befor join:\n %s\n---",buffer);
	//	printf("file befor join:\n %s\n---",file);
		file = ft_strjoin(file, buffer);
	//	printf("buffer after join:\n %s\n---",buffer);
	//	printf("file after join:\n %s\n---",file);
	//	printf("==end while==\n");	
	}
	//printf("file \n%s",file);
	line = ft_strsplit(file,'\n');
	int lenght = 0;
	
	//while (*line)
	//{
	//	printf("%s\n\n",*line);
	//	line++;
	//}
	int i = 0;
	while (line[i])
	{
		lenght++;
		i++;
	}
	if (i < lengh)
	printf("%d\n",lenght);
	return (0);
}

int main(void)
{
	int fd = open("file", O_RDONLY);
	char *line;
	//while (get_next_line(fd, line) == 1)
	get_next_line(fd, &line);
	//printf("line %s\n",line);
}
