/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 14:20:15 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/14 16:26:32 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		true(unsigned char c1, unsigned char c2)
{
	if (c1 == c2 && c1 != '\0')
		return (1);
	else
		return (0);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	int			i;

	i = 0;
	while (true((unsigned char)s1[i], (unsigned char)s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
