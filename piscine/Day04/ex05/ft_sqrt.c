/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:28:49 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/17 01:44:59 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int n;
	int result;
	int square;

	result = 1;
	n = 2;
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0 || nb == 1)
	{
		return (nb);
	}
	while (result < nb)
	{
		result = n * n;
		n++;
	}
	square = (nb % (n - 1) == 0) ? n - 1 : 0;
	return (square);
}
