/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:52:27 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/19 19:58:02 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		chars_counter(char *str, int i, char c)
{
	int count;

	count = 1;
	while (str[i])
	{
		if (str[i + 1] != c)
			count++;
		else
			break ;
		i++;
	}
	if (str[i] == '\0')
		count--;
	return (count);
}
