/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:40:26 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/19 18:57:51 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int res;

	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	res = ft_strncmp(s1, s2, n);
	res = (res == 0) ? 1 : 0;
	return (res);
}
