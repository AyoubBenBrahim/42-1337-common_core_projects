/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 23:06:23 by ahel-men          #+#    #+#             */
/*   Updated: 2019/07/18 16:40:13 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pix(t_option *opt, t_bres bres, t_crd coord)
{
	int i;

	i = -1;
	while (i++ < bres.dx)
	{
		mlx_pixel_put(opt->mlx, opt->win, bres.x, bres.y, coord.color);
		while (bres.p >= 0)
		{
			bres.p = bres.p - 2 * bres.dx;
			if (bres.swap)
				bres.x += bres.s1;
			else
				bres.y += bres.s2;
		}
		bres.p += 2 * bres.dy;
		if (bres.swap)
			bres.y += bres.s2;
		else
			bres.x += bres.s1;
	}
}

void	zoom(t_option **opt, t_crd *coord)
{
	coord->x1 *= (*opt)->zoom;
	coord->y1 *= (*opt)->zoom;
	coord->x2 *= (*opt)->zoom;
	coord->y2 *= (*opt)->zoom;
}

void	decalage(t_option **opt, t_crd *coord)
{
	coord->x1 += (*opt)->absc;
	coord->y1 += (*opt)->ordn;
	coord->x2 += (*opt)->absc;
	coord->y2 += (*opt)->ordn;
}

void	do_bres(t_bres *bres, t_crd *coord)
{
	bres->x = coord->x1;
	bres->y = coord->y1;
	bres->dx = abs(coord->x2 - coord->x1);
	bres->dy = abs(coord->y2 - coord->y1);
	bres->s1 = sign(coord->x2 - coord->x1);
	bres->s2 = sign(coord->y2 - coord->y1);
	bres->swap = 0;
}

void	draw_line(t_option *opt, t_crd coord)
{
	t_bres bres;

	zoom(&opt, &coord);
	projection(&coord.x1, &coord.y1, &coord.z1, opt);
	projection(&coord.x2, &coord.y2, &coord.z2, opt);
	if (opt->rotation == True)
		ft_rotate(&coord, opt);
	decalage(&opt, &coord);
	do_bres(&bres, &coord);
	if (coord.x2 > opt->win_x++ || coord.y2 > opt->win_y++)
		return ;
	mlx_pixel_put(opt->mlx, opt->win, coord.x1, coord.y1, coord.color);
	if (bres.dy > bres.dx)
	{
		bres.temp = bres.dx;
		bres.dx = bres.dy;
		bres.dy = bres.temp;
		bres.swap = 1;
	}
	bres.p = 2 * bres.dy - bres.dx;
	ft_pix(opt, bres, coord);
	mlx_pixel_put(opt->mlx, opt->win, coord.x2, coord.y2, coord.color);
}
