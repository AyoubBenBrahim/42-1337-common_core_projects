/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:34:48 by ahel-men          #+#    #+#             */
/*   Updated: 2019/07/13 21:53:16 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_by_x(t_option *opt, t_crd *coord)
{
	int	prv1;
	int	prv2;

	prv1 = coord->y1;
	prv2 = coord->z1;
	coord->y1 = (prv1 * cos(opt->anglex)) + (prv2 * sin(opt->anglex));
	coord->z1 = (-prv1 * sin(opt->anglex)) + (prv2 * cos(opt->anglex));
	prv1 = coord->y2;
	prv2 = coord->z2;
	coord->y2 = (prv1 * cos(opt->anglex)) + (prv2 * sin(opt->anglex));
	coord->z2 = (-prv1 * sin(opt->anglex)) + (prv2 * cos(opt->anglex));
}

void	ft_rotate(t_crd *coord, t_option *opt)
{
	if (opt->keycod == X_PRESSED)
		rotate_by_x(opt, coord);
}
