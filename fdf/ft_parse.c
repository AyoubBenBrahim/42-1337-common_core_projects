/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:15:07 by ahel-men          #+#    #+#             */
/*   Updated: 2019/07/18 21:50:57 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(char ***tab)
{
	int i;

	if (!(*tab))
		return ;
	i = 0;
	while ((*tab)[i] != NULL)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	(*tab) = NULL;
}

int		ft_manipulate(char **tab, t_option **opt, t_list2 ***tmp, t_stock *s)
{
	(*(*tmp))->z = ft_atoi(tab[s->i]);
	(*(*tmp))->cart_x = ++s->x;
	(*(*tmp))->cart_y = (*opt)->count;
	if (!((*(*tmp))->next = (t_list2 *)ft_memalloc(sizeof(t_list2))))
		return (0);
	if (ft_strchr(tab[s->i], ','))
		(*(*tmp))->color = ft_atoi_base(16, ft_strchr(tab[s->i], 'x') + 1);
	else
		(*(*tmp))->color = 16777215;
	(*opt)->color = (*(*tmp))->color;
	return (1);
}

void	free_arr(char ***tab, char **str)
{
	free_tab(tab);
	free(*str);
}

int		ft_tab_iter(char *str, t_list2 **tmp, t_option *opt, t_stock s)
{
	int x_nb;

	s.i = -1;
	while (s.tab[++s.i])
	{
		if (!(ft_manipulate(s.tab, &opt, &tmp, &s)))
		{
			free_arr(&s.tab, &str);
			return (0);
		}
		if (opt->count == 0)
			*(s.x_ligne) = (*tmp)->cart_x;
		x_nb = (*tmp)->cart_x;
		*tmp = (*tmp)->next;
	}
	return (x_nb);
}

int		ft_parse(char *str, t_list2 **tmp, t_option *opt)
{
	t_stock		s;
	static int	x_nb1;

	s.x = -1;
	(*tmp)->cart_x = s.x;
	(*tmp)->cart_y = opt->count;
	s.tab = ft_strsplit(str, ' ');
	if (!check_file(s.tab))
	{
		free_arr(&s.tab, &str);
		return (0);
	}
	s.x_ligne = &x_nb1;
	s.x_nb = ft_tab_iter(str, tmp, opt, s);
	if (*(s.x_ligne) != s.x_nb)
	{
		ft_putendl("error : lines length");
		free_arr(&s.tab, &str);
		return (0);
	}
	free_tab(&s.tab);
	(*tmp)->next = NULL;
	return (1);
}
