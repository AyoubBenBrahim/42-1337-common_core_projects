/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 03:16:55 by ayb*****          #+#    #+#             */
/*   Updated: 2019/01/18 03:21:43 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int bb;
	int cc;
	int dd;

	cc = *******c;
	dd = ****d;
	bb = *b;
	*******c = ***a;
	****d = cc;
	*b = dd;
	***a = bb;
}
