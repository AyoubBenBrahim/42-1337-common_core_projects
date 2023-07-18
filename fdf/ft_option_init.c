/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:45:04 by ayb*****          #+#    #+#             */
/*   Updated: 2019/07/15 13:45:12 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_option_init(t_option *option, void *mlx, void *win)
{
	mlx_clear_window(mlx, win);
	option->mlx = mlx;
	option->win = win;
	option->win_x = 800;
	option->win_y = 800;
	option->zoom = 3;
	option->absc = 350;
	option->ordn = 300;
	option->rotation = False;
	option->iso = True;
	option->z = 2;
	option->anglex = 0;
}
