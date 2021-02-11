/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:29:33 by aybouras          #+#    #+#             */
/*   Updated: 2019/05/05 15:44:40 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int		manage_lines(const int fd, char **the_rest, char **line)
{
	int		index;
	char	*temp;

	if ((index = get_index_of_line_feed(the_rest[fd])) != -1)
	{
		*line = ft_strsub(the_rest[fd], 0, index);
		if (index == (int)ft_strlen(the_rest[fd]) - 1)
			temp = ft_strnew(0);
		else
			temp = ft_strdup(((the_rest[fd]) + (index + 1)));
		free(the_rest[fd]);
		the_rest[fd] = temp;
		return (1);
	}
	if (ft_strlen(the_rest[fd]))
	{
		*line = ft_strsub(the_rest[fd], 0, ft_strlen(the_rest[fd]));
		*the_rest[fd] = '\0';
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	static char *the_rest[4864];
	char		*tmp;
	int			res;
	int			index;

	if (fd < 0 || !line || (read(fd, buffer, 0)) < 0 || fd > 4864)
		return (-1);
	while ((res = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (the_rest[fd] == NULL)
			the_rest[fd] = ft_strnew(0);
		buffer[res] = '\0';
		tmp = the_rest[fd];
		the_rest[fd] = ft_strjoin(tmp, buffer);
		free(tmp);
		if ((index = get_index_of_line_feed(the_rest[fd])) != -1)
			break ;
	}
	if (manage_lines(fd, the_rest, line) == 1)
		return (1);
	if (res == 0)
		return (0);
	return (0);
}
