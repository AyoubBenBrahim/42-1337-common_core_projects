/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:02:49 by ahel-men          #+#    #+#             */
/*   Updated: 2019/07/13 22:02:35 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int button, int x, int y, t_option *opt)
{
	if (button == RIGHT_BUTTON)
	{
		opt->keycod = button;
		mlx_clear_window(opt->mlx, opt->win);
		draw(opt->head, opt);
	}
	else if (button == LEFT_BUTTON)
	{
		opt->absc = x;
		opt->ordn = y;
		mlx_clear_window(opt->mlx, opt->win);
		draw(opt->head, opt);
	}
	return (0);
}
