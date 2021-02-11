/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:36:02 by aybouras          #+#    #+#             */
/*   Updated: 2019/07/18 22:07:58 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_number(char *str)
{
	int k;

	k = 0;
	if (str[0] == '-' && ft_isdigit(str[1]))
		k++;
	while (str[k])
	{
		if (!ft_isdigit(str[k]))
			return (0);
		k++;
	}
	return (1);
}

int		is_hexa(char c)
{
	return ((c == 'A') || (c == 'B') || (c == 'C') || (c == 'D')
			|| (c == 'E') || (c == 'F') ? 1 : 0);
}

int		do_something(char *str, int i)
{
	int comma_count;

	comma_count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		if (str[i] == 'x')
		{
			i++;
			break ;
		}
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !is_hexa(ft_toupper(str[i])))
			return (0);
		i++;
	}
	if (ft_strstr(str, ",0x") && comma_count == 1)
		return (1);
	return (0);
}

int		is_color(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			break ;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (do_something(str, i));
}

int		check_file(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (!is_number(tab[i]) && !is_color(tab[i]))
		{
			write(1, "there is invalid coordinate in the file: ", 41);
			ft_putendl(tab[i]);
			return (0);
		}
		i++;
	}
	return (1);
}
