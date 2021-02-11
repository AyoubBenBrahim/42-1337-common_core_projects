/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:29:33 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/25 20:17:39 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		get_index_of_line_feed11(char *str)
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

int		manage_lines11(const int fd, char **the_rest, char **line)
{
	int		index;
	char	*temp;

	if (!*the_rest)
		return (0);
	if ((index = get_index_of_line_feed11(*the_rest)) != -1)
	{
		*line = ft_strsub(*the_rest, 0, index);
		if (index == (int)ft_strlen(*the_rest) - 1)
			temp = ft_strnew(0);
		else
			temp = ft_strdup(((*the_rest) + (index + 1)));
		free(*the_rest);
		*the_rest = temp;
		return (1);
	}
	if (ft_strlen(*the_rest))
	{
		*line = ft_strsub(*the_rest, 0, ft_strlen(*the_rest));
		free(*the_rest);
		return (1);
	}
	else
		ft_strdel(&(*the_rest));
	return (0);
}

int		get_next(const int fd, char **line, t_parse *prs)
{
	char		buffer[BUFF_SIZE + 1];
	// static char *the_rest[4864];
	char		*tmp;
	int			res;

	// if (!flag)
	// 	return (free_buffer_before_exit(the_rest, fd));
	// prs->the_rest = the_rest;
	if (fd < 0 || !line || (read(fd, buffer, 0)) < 0 || fd > 4864)
		return (-1);
	while ((res = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (prs->the_rest == NULL)
			prs->the_rest = ft_strnew(0);
		buffer[res] = '\0';
		tmp = prs->the_rest;
		prs->the_rest = ft_strjoin(tmp, buffer);
		free(tmp);
		if (get_index_of_line_feed11(prs->the_rest) != -1)
			break ;
	}
	if (manage_lines11(fd, &prs->the_rest, line) == 1)
		return (1);
	if (res == 0)
		return (0);
	return (0);
}
