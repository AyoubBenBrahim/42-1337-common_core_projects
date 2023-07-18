/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 05:44:30 by ayb*****          #+#    #+#             */
/*   Updated: 2019/01/30 00:18:46 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_words_tables(char **tab)
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

int main()
{

	char *tab[4];

	tab[0] = "12";
	tab[1] = "34";
	tab[2] = "56";
	tab[3] = 0;

	char *tabbb[] = {"abc", "def", "ghi"};


ft_print_words_tables(tabbb);
	return (0);
}
