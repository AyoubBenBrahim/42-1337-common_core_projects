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
#define BUFF_SIZE 50

int get_index_of_line_feed(char *str)
{
	int i;
	int index;
	
	i = 0;
	index = -1;
	while (str[i])
	{
		if (str[i] == '\n')
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
	int i;
	char buffer[BUFF_SIZE + 1];
	char *temp;
 	static char *file;
	int res;
	int index;

	index = -1;
	while ((res = read(fd, buffer, BUFF_SIZE)) > 0)
	{

//printf("oldFile %s\n", file);

		if (file == NULL)
			file = "";
		buffer[res] = '\0';
		file = ft_strjoin(file, buffer);

//printf("buffer %s\n", buffer);
//printf("fileJoin %s\n", file);
//printf("res while %d\n", res);
//printf("-----\n");
		if ((index = get_index_of_line_feed(file)) != -1)
			break ;
	}

//printf("res after while %d\n", res);



	if ((index = get_index_of_line_feed(file)) != -1)
	{ 
//printf("after %s\n", file);
			*line = ft_strsub(file, 0, index);
//printf("line %s\n", *line);
			if (index == ft_strlen(file) - 1)
				temp = strdup("");
			else
				temp = strdup((file + (index + 1)));
//printf("temp %s\n", temp);
			file = NULL;
			file = temp;
			temp = NULL;
//printf("new %s\n",file);		
			return (1);
	}


	if (res == 0 && file)
	{		
//			*line = file;
	file = NULL;
		return (0);		
	}


	return (0);

}




int main(int arc, char ** arv)
{
	int fd = open(arv[1], O_RDONLY);
	char *line;

	while (get_next_line(fd, &line))
	{	
		printf("%s\n",line);
	
//printf("================\n");
	}
}
