/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_to_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:36:57 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:36:59 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start_to_end(t_farm *farm, t_mem *mem)
{
	int i;

	i = 1;
	while (1)
	{
		if (!(read_line(mem)))
			break ;
	}
	print_lines(mem);
	ft_putstr("\n");
	while (i <= farm->ants)
	{
		ft_putchar('L');
		ft_putnbr(i);
		ft_putchar('-');
		ft_putstr(farm->end->name);
		i++;
		ft_putchar(' ');
	}
	free_lem_in(mem);
	exit(0);
}
