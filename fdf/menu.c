/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:06:27 by aybouras          #+#    #+#             */
/*   Updated: 2019/07/10 18:07:54 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_option *opt)
{
	mlx_string_put(opt->mlx, opt->win, 63, 70, 16777215, "INSTRUCTIONS");
	mlx_string_put(opt->mlx, opt->win, 63, 80, 15532032, "------------");
	mlx_string_put(opt->mlx, opt->win, 10, 140, 15532032, "Axial Rotation   :");
	mlx_string_put(opt->mlx, opt->win, 195, 140, 16777215, "Press x");
	mlx_string_put(opt->mlx, opt->win, 10, 184, 15532032, "Move the shape   :");
	mlx_string_put(opt->mlx, opt->win, 196, 184, 16777215, "Arrows/Left click");
	mlx_string_put(opt->mlx, opt->win, 10, 228, 15532032, "change the color :");
	mlx_string_put(opt->mlx, opt->win, 196, 228, 16777215, "Mouse left button");
	mlx_string_put(opt->mlx, opt->win, 10, 272, 15532032, "Zoom In/out      :");
	mlx_string_put(opt->mlx, opt->win, 196, 272, 16777215, "</>");
	mlx_string_put(opt->mlx, opt->win, 10, 313, 15532032, "height++ / --    :");
	mlx_string_put(opt->mlx, opt->win, 196, 313, 16777215, "+/-");
	mlx_string_put(opt->mlx, opt->win, 10, 345, 15532032, "Exit             :");
	mlx_string_put(opt->mlx, opt->win, 196, 345, 16777215, "ESC");
	mlx_string_put(opt->mlx, opt->win, 10, 380, 15532032, "Initialisation   :");
	mlx_string_put(opt->mlx, opt->win, 196, 380, 16777215, "Space");
}
