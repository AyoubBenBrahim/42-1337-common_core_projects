/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:10:19 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/15 15:18:04 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int index;
	int new_size;
	int in_desordrer;

	in_desordrer = 1;
	new_size = size;
	while (in_desordrer)
	{
		in_desordrer = 0;
		index = 0;
		while (index < new_size - 1)
		{
			if (tab[index] > tab[index + 1])
			{
				swap(&tab[index], &tab[index + 1]);
				in_desordrer = 1;
			}
			index++;
		}
		new_size--;
	}
}
