/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:36:05 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/08 19:38:12 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*allocates_array(int size)
{
	char *array;

	array = (char *)malloc(sizeof(char) * size + 1);
	if (array == NULL)
		return (NULL);
	return (array);
}

static char		*case_zero_and_min_int(int n)
{
	char *to_string;

	if (n == 0)
	{
		to_string = allocates_array(1);
		if (to_string == NULL)
			return (NULL);
		to_string[0] = '0';
		to_string[1] = '\0';
	}
	if (n == -2147483648)
	{
		to_string = allocates_array(10);
		if (to_string == NULL)
			return (NULL);
		to_string = ft_strcat(ft_itoa(-214748), ft_itoa(3648));
	}
	return (to_string);
}

static char		*conversion(int n, int signe, int nbr_chars)
{
	char	*to_string;
	int		i;
	int		temp;

	temp = n;
	while (temp != 0)
	{
		nbr_chars++;
		temp = temp / 10;
	}
	to_string = allocates_array(nbr_chars);
	if (to_string == NULL)
		return (NULL);
	to_string[nbr_chars] = '\0';
	if (signe == -1)
		to_string[0] = '-';
	i = nbr_chars - 1;
	while (n)
	{
		to_string[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (to_string);
}

char			*ft_itoa(int n)
{
	int i;
	int nbr_chars;
	int signe;

	nbr_chars = 0;
	signe = 1;
	i = 0;
	if (n == 0 || n == -2147483648)
		return (case_zero_and_min_int(n));
	if (n < 0)
	{
		signe = -1;
		n = n * (-1);
		nbr_chars++;
	}
	return (conversion(n, signe, nbr_chars));
}
