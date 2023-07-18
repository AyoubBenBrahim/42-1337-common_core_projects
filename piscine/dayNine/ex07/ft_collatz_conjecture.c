/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 05:46:46 by ayb*****          #+#    #+#             */
/*   Updated: 2019/01/18 05:58:51 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	collatz(unsigned int base, int count)
{
	if (base == 1)
	{
		return (count);
	}
	if (base % 2 == 0)
	{
		base = base / 2;
		count++;
		collatz(base, count);
	}
	else
	{
		base = base * 3 + 1;
		count++;
		collatz(base, count);
	}
}

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	int count;

	count = 0;
	return (collatz(base, count));
}
