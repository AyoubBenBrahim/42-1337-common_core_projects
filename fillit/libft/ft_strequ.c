/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:21:10 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/19 19:02:26 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int res;

	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	res = ft_strcmp(s1, s2);
	res = (res == 0) ? 1 : 0;
	return (res);
}
