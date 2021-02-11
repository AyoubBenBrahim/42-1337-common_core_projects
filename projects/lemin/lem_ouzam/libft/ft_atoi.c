/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 17:16:24 by ouzamhar          #+#    #+#             */
/*   Updated: 2020/11/05 10:50:22 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	true(char s)
{
	if (s == ' ' || s == '\t' || s == '\v' || s == '\f' || s == '\r' ||
			s == '\n')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int				i;
	int				j;
	int				s;

	i = 0;
	j = 0;
	s = 1;
	while (true(str[j]))
		j++;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			s = -1;
		j++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		i = i * 10 + (str[j] - '0');
		j++;
	}
	return (i * s);
}
