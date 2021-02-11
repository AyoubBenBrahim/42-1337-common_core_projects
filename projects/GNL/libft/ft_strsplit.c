/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:53:20 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/22 19:15:50 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words_counter(char *str, char c)
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

static int		chars_counter(char *str, int i, char c)
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

static char		**memdel(char **ap)
{
	free(*ap);
	*ap = NULL;
	return (NULL);
}

static char		**fill_array(char *str, char **array, char c)
{
	int			i;
	int			j;
	int			k;
	char		*sub_array;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			sub_array = malloc(sizeof(char) * (chars_counter(str, i, c) + 1));
			if (!sub_array)
				return (memdel((array)));
			k = 0;
			while (str[i] != c && str[i] != '\0')
				sub_array[k++] = str[i++];
			sub_array[k] = '\0';
			array[j++] = sub_array;
		}
	}
	array[j] = NULL;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char **array;

	if (!s)
		return (NULL);
	array = (char**)malloc(sizeof(char*) * (words_counter((char *)s, c) + 1));
	if (array == NULL)
		return (NULL);
	array = fill_array((char *)s, array, c);
	return (array);
}
