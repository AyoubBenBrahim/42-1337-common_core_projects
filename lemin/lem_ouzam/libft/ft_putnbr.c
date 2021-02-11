/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:28:33 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/19 17:37:00 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int m;

	if (n < 0)
	{
		m = n * (-1);
		ft_putchar('-');
	}
	else
		m = n;
	if (m > 9)
	{
		ft_putnbr(m / 10);
		ft_putnbr(m % 10);
	}
	else
		ft_putchar(m + '0');
}
