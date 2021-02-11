/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 20:18:52 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/14 15:47:29 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	char tab[2][2];

	tab[0][0] = '0';
	tab[0][1] = '0';
	tab[1][0] = '0';
	tab[1][1] = '1';
	while (tab[0][0] <= '9')
	{
		while (tab[0][1] <= '9')
		{
			second_loop(tab);
			tab[0][1]++;
			tab[1][0] = tab[0][0];
			tab[1][1] = tab[0][1] + 1;
		}
		tab[0][0]++;
		tab[0][1] = '0';
		tab[1][0] = tab[0][0];
		tab[1][1] = tab[0][1] + 1;
	}
}

void	first_loop(char t1[2][2])
{
	while (t1[1][1] <= '9')
	{
		if (t1[0][0] == '9' && t1[0][1] == '8')
		{
			ft_putchar(t1[0][0]);
			ft_putchar(t1[0][1]);
			ft_putchar(' ');
			ft_putchar(t1[1][0]);
			ft_putchar(t1[1][1]);
		}
		else
		{
			ft_putchar(t1[0][0]);
			ft_putchar(t1[0][1]);
			ft_putchar(' ');
			ft_putchar(t1[1][0]);
			ft_putchar(t1[1][1]);
			ft_putchar(',');
			ft_putchar(' ');
		}
		t1[1][1]++;
	}
}

void	second_loop(char t2[2][2])
{
	while (t2[1][0] <= '9')
	{
		first_loop(t2);
		t2[1][0]++;
		t2[1][1] = '0';
	}
}
