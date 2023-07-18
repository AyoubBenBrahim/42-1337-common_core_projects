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
	char buffer[BUFF_SIZE + 1];
	char *temp;
 	static char *file;
	int res;
	int index;

	index = -1;
	while ((res = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (file == NULL)
			file = "";
		buffer[res] = '\0';
		file = ft_strjoin(file, buffer);
		if ((index = get_index_of_line_feed(file)) != -1)
			break ;
	}
	if ((index = get_index_of_line_feed(file)) != -1)
	{ 
			*line = ft_strsub(file, 0, index);
			if (index == (int)ft_strlen(file) - 1)
				temp = ft_strdup("");
			else
				temp = ft_strdup((file + (index + 1)));
			file = NULL;
			file = temp;
			temp = NULL;	
			return (1);
	}
	if (res == 0)		
		return (0);		
	return (0);
}




int main(int arc, char ** arv)
{
	int fd = open(arv[1], O_RDONLY);
	char *line;

	while (get_next_line(fd, &line))
	{	
		printf("%s\n",line);
	}
}

