/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:41:26 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/20 11:16:16 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb(int n)
{
	int				i;
	unsigned int	m;

	i = 1;
	if (n < 0)
	{
		i++;
		m = n * -1;
	}
	else
		m = n;
	while (m > 9)
	{
		m = m / 10;
		i++;
	}
	return (i);
}

static void		putn(int n, char *str)
{
	unsigned int m;

	if (n < 0)
	{
		m = n * -1;
		*(str - nb(n) + 1) = '-';
	}
	else
		m = n;
	if (m > 9)
	{
		putn(m / 10, str - 1);
		putn(m % 10, str);
	}
	else
		*str = m + '0';
}

char			*ft_itoa(int n)
{
	char *s;

	if (!(s = (char *)malloc(sizeof(*s) * (nb(n) + 1))))
		return (0);
	putn(n, s + nb(n) - 1);
	s[nb(n)] = '\0';
	return (s);
}
