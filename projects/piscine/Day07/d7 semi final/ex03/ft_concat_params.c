/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:43:19 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/28 01:31:15 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int size_of_params(int argc, char **argv)
{
	int i;
	int j;
	int size;

	i = 1;
	size = 0;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j] != '\0')
		{
			size++;
			j++;
		}
		i++;
	}
	return (size + 1);
}

char	*ft_concat_params(int argc, char **argv)
{
    int i;
    int j;
    int k;
    char *tab;
    
    i = 1;
    j = 0;
    k = 0;
    tab = (char *)malloc(sizeof(char) * size_of_params(argc, argv));
    while(i < argc)
    {
        while(argv[i][j] != '\0')
        {
            tab[k] = argv[i][j];
            k++;
            j++;
        }
		
        tab[k] = '\n';
		k++;
        j = 0;
        i++;
    }
    tab[k - 1] = '\0';
    
     return (tab);
}

int main(int argc, char **argv)
{
	char *t;	
   	t = ft_concat_params(argc, argv);

	int i = 0;
	while (t[i] != '\0')
	{
	    printf("%c",t[i]);
	 	i++;
    }
return (0);
}
