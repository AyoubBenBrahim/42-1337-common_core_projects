/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:39:10 by ayb*****          #+#    #+#             */
/*   Updated: 2019/01/18 15:46:12 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	convert_to_binary(int nbr)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (nbr != 0)
	{
		sum = sum + (nbr % 2);
		nbr = nbr / 2;
		i++;
	}
	return (sum);
}

unsigned int	ft_active_bits(int value)
{
	int		nbr_bits;
	int		i;

	if (value < 0)
		value = -value;
	if (value == 0)
		nbr_bits = 0;
	if (value == 1)
		nbr_bits = 1;
	else
		nbr_bits = convert_to_binary(value);
	return (nbr_bits);
}
