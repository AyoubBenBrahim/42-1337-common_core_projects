/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:41:17 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/17 21:47:05 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		index;
	int		size;
	char	temp;

	index = 0;
	size = 0;
	while (str[index] != '\0')
	{
		size++;
		index++;
	}
	size--;
	index = 0;
	while (index < size)
	{
		temp = str[size];
		str[size] = str[index];
		str[index] = temp;
		index++;
		size--;
	}
	return (str);
}
