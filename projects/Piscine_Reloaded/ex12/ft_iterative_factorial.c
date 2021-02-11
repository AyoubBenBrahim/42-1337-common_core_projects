/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:18:28 by aybouras          #+#    #+#             */
/*   Updated: 2019/03/25 18:30:22 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int ft;
	int i;

	if (nb == 0)
	{
		return (1);
	}
	else if (nb > 0 && nb <= 12)
	{
		ft = 1;
		i = 1;
		while (i <= nb)
		{
			ft = ft * i;
			i++;
		}
		return (ft);
	}
	else
	{
		return (0);
	}
}
