/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 01:41:28 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/30 08:50:34 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_spaces(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int		word_counts(char *str)
{
	int nbr_words;
	int i;

	nbr_words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (check_spaces(str[i]))
		{
			if (!check_spaces(str[i + 1]))
				nbr_words++;
		}
		i++;
	}
	if (str[i - 1] == ' ')
		nbr_words--;
	return (nbr_words);
}

int		count_characters(char *str, int i)
{
	int char_count;

	char_count = 0;
	while (str[i])
	{
		if (!check_spaces(str[i + 1]))
			char_count++;
		else
			break ;
		i++;
	}
	return (char_count);
}

char	**fill_array_with_subarray_elements(char *str, char **array)
{
	int		i;
	int		j;
	int		k;
	char	*sub_array;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (check_spaces(str[i]))
			i++;
		else
		{
			sub_array = malloc(sizeof(char) * (count_characters(str, i) + 1));
			k = 0;
			while (!check_spaces(str[i]) && str[i] != '\0')
			{
				sub_array[k++] = str[i++];
			}
			sub_array[k] = '\0';
			array[j++] = sub_array;
		}
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split_whitespaces(char *str)
{
	char **array;

	array = (char**)malloc(sizeof(char*) * (word_counts(str) + 10));
	array = fill_array_with_subarray_elements(str, array);
	return (array);
}
