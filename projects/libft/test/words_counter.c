/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:50:05 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/19 20:09:16 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		words_counter(char *str, char c)
{
	int nbr;
	int i;

	nbr = 0;
	i = 0;
	if (!*str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (str[i + 1] != c)
				nbr++;
		}
		i++;
	}
	if (str[0] != c)
		nbr++;
	if (str[i - 1] == c)
		nbr--;
	return (nbr);
}
