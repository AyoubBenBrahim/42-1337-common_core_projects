/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:53:20 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/22 18:34:28 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static char        **fill_array(char *str, char **array, char c)
{
	int            i;
	int            j;
	int            k;
	char        *sub_array;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			sub_array = malloc(sizeof(char) * (chars_counter(str, i, c) + 1));
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

char            **ft_strsplit(char const *s, char c)
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

int main() 
{
	char **tab;

		tab = ft_strsplit("*12**345*6789", '*');
	//	tab = ft_strsplit(NULL, 0);
	//	tab = ft_strsplit(NULL, 'a');
	//tab = ft_strsplit("", '*');
	while (*tab)
	{
		printf("%s\n",*tab);
		tab++;
	}
	ft_memdel((void **)tab);
	printf("after memdel\n");
	if (!*tab)
		printf("NULL");
	while (*tab)
	{
		printf("%s\n",*tab);
		tab++;
	}


	return 0;
}
