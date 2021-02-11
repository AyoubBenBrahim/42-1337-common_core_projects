/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 01:41:28 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/30 00:39:42 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int check_spaces(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return 1;
	return 0;
}

int     word_counts(char *str)
{
	int space_count;
	int i;

	space_count = 0;
	i = 0;
	while(str[i] != '\0')
	{
		if(check_spaces(str[i]))
		{
			if(check_spaces(str[i]))
				space_count++;
		}
		i++;
	}
	return (space_count);
}

int     count_characters(char *str, int i)
{
	int char_count;

	char_count = 0;
	while(str[i])
	{
		if(!check_spaces(str[i+1]))
			char_count++;
		else
			break;
		i++;
	}
	return (char_count);
}

char    **fill_array_with_subarray_elements(char *str, char **array)
{
    int     i;
    int     j;
    int     k;
    char    *sub_array;
    
    i = 0;
    j = 0;
    while(str[i] != '\0')
    {
        if(check_spaces(str[i]))
            i++;
        else
        {
            sub_array = malloc(sizeof(char) * (count_characters(str, i) + 1));
            k = 0;
            while(!check_spaces(str[i]) && str[i] != '\0')
            {
                sub_array[k] = str[i];
                k++;
                i++;
            }
            sub_array[k] = '\0';
            array[j] = sub_array;
            j++;
       }
    }
    array[j] = NULL;
    return (array);
}

char    **ft_split_whitespaces(char *str)
{
	char    **array;

    array = (char**)malloc(sizeof(char*)*(word_counts(str) + 1));
    array = fill_array_with_subarray_elements(str,array);
	return array;
}

void    ft_print_words_tables(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i] != '\0')
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

int main() {

	char    **tab;
	char    tableau[] ="sa abcd sa bc st 12 kjaksjkj nc oppp ieiei";

	tab = ft_split_whitespaces(tableau);

	ft_print_words_tables(tab);


/*	int j;
	for(i = 0;i<9;i++)
	{
		for(j = 0;j<5;j++)
			printf("%c", tab[i][j]);

		printf("\n");
	}
*/
	return 0;
}

