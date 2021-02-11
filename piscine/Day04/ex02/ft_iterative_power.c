/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:19:12 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/16 11:51:40 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int res;

	i = 1;
	res = 1;
	if (power > 0)
	{
		while (i <= power)
		{
			res = res * nb;
			i++;
		}
		return (res);
	}
	else if (power == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
