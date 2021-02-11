/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:35:26 by aybouras          #+#    #+#             */
/*   Updated: 2019/03/25 18:43:24 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb >= 1 && nb <= 12)
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
	else if (nb == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
