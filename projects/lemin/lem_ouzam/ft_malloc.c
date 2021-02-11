/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:34:32 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:34:34 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_line(t_mem *mem, char *line)
{
	t_hold	*hold;

	if (!(hold = malloc(sizeof(t_hold))))
	{
		free(line);
		error(mem);
	}
	hold->adr = line;
	hold->next = NULL;
	if (mem->line)
	{
		mem->lline->next = hold;
		mem->lline = hold;
	}
	else
	{
		mem->line = hold;
		mem->lline = hold;
	}
}

char	*linepart(char *src, int l)
{
	char *part;

	part = NULL;
	if (!(part = malloc(sizeof(char) * (l + 1))))
		return (0);
	part[l] = '\0';
	while (l--)
		part[l] = src[l];
	return (part);
}

char	*read_line(t_mem *mem)
{
	char	temp[4095];
	char	*line;
	int		l;
	int		f;

	l = 0;
	line = NULL;
	while ((f = read(0, temp + l, 1)) > 0 && temp[l] != '\n')
		l++;
	if (f == -1)
		error(mem);
	if (l == 0)
		return (0);
	if (!(line = linepart(temp, l)))
		error(mem);
	add_line(mem, line);
	return (line);
}

int		add_mem(t_mem *mem, void *val)
{
	t_hold *hold;

	if (!(hold = malloc(sizeof(t_hold))))
	{
		free(val);
		error(mem);
	}
	hold->adr = val;
	hold->next = NULL;
	if (mem->hld)
	{
		mem->last->next = hold;
		mem->last = hold;
	}
	else
	{
		mem->hld = hold;
		mem->last = hold;
	}
	return (1);
}

void	*ft_malloc(size_t size, t_mem *mem)
{
	void	*val;

	if (!(val = malloc(size)))
		error(mem);
	add_mem(mem, val);
	return (val);
}
