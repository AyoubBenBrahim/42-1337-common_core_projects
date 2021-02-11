/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:29:33 by aybouras          #+#    #+#             */
/*   Updated: 2019/05/04 12:53:35 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_index_of_line_feed(char *str)
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

int		manage_lines(char **file, char **line)
{
	int		index;
	char	*temp;

	if ((index = get_index_of_line_feed(*file)) != -1)
	{
		*line = ft_strsub(*file, 0, index);
		if (index == (int)ft_strlen(*file) - 1)
			temp = ft_strnew(0);
		else
			temp = ft_strdup(((*file) + (index + 1)));
		ft_memdel((void **)file);
		*file = temp;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buffer[4096][BUFF_SIZE + 1];
	static char *file;
	char		*tmp;
	int			res;
	int			index;

	if(fd < 0 || !line ||(read(fd, buffer[fd], 0)) < 0)
		return (-1);
	while ((res = read(fd, buffer[fd], BUFF_SIZE)) > 0)
	{
		if (file == NULL)
			file = ft_strnew(0);
		buffer[fd][res] = '\0';
		tmp = file;
		file = ft_strjoin(tmp, buffer[fd]);
		free(tmp);
		if ((index = get_index_of_line_feed(file)) != -1)
			break ;
	}
	if (manage_lines(&file, line) == 1)
		return (1);
	if (res == 0)
		return (0);
	return (0);
}

int		main(int arc, char **arv)
{
	int		fd;
	char	*line;
	int ret;

	fd = open(arv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		printf("|%d| ", ret);
		printf("%s\n", line);
		free(line);
	}
	printf ("|%d|", ret);
}
