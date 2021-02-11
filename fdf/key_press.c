/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:18:17 by aybouras          #+#    #+#             */
/*   Updated: 2019/07/13 22:08:09 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_arrows(t_option *opt)
{
	if (opt->keycod == ARROW_DOWN)
	{
		mlx_clear_window(opt->mlx, opt->win);
		opt->ordn += 150;
		draw(opt->head, opt);
	}
	else if (opt->keycod == ARROW_UP)
	{
		mlx_clear_window(opt->mlx, opt->win);
		opt->ordn -= 150;
		draw(opt->head, opt);
	}
	else if (opt->keycod == ARROW_RIGHT)
	{
		mlx_clear_window(opt->mlx, opt->win);
		opt->absc += 150;
		draw(opt->head, opt);
	}
	else if (opt->keycod == ARROW_LEFT)
	{
		mlx_clear_window(opt->mlx, opt->win);
		opt->absc -= 150;
		draw(opt->head, opt);
	}
}

void	iso_para(t_option *opt)
{
	if (opt->keycod == I_PRESSED)
	{
		opt->iso = True;
		mlx_clear_window(opt->mlx, opt->win);
		draw(opt->head, opt);
	}
	else if (opt->keycod == P_PRESSED)
	{
		opt->iso = False;
		mlx_clear_window(opt->mlx, opt->win);
		draw(opt->head, opt);
	}
}

void	manage_alpha(t_option *opt)
{
	if (opt->keycod == M_PRESSED)
	{
		mlx_clear_window(opt->mlx, opt->win);
		menu(opt);
		draw(opt->head, opt);
	}
	else if (opt->keycod == X_PRESSED && opt->iso == True)
	{
		opt->rotation = True;
		opt->anglex += 0.2;
		mlx_clear_window(opt->mlx, opt->win);
		draw(opt->head, opt);
		opt->rotation = False;
	}
	else if (opt->keycod == Z_UP && opt->iso == True)
	{
		opt->z += 2;
		mlx_clear_window(opt->mlx, opt->win);
		draw(opt->head, opt);
	}
}

void	ft_zoom(t_option *opt)
{
	if (opt->keycod == ZOOM_OUT && opt->iso == True)
	{
		if (opt->zoom == 3)
			return ;
		mlx_clear_window(opt->mlx, opt->win);
		string_put(opt, ft_itoa(opt->zoom));
		if (opt->zoom >= 3)
			opt->zoom -= 3;
		draw(opt->head, opt);
	}
	else if (opt->keycod == ZOOM_IN && opt->iso == True)
	{
		if (opt->zoom == 36)
			return ;
		mlx_clear_window(opt->mlx, opt->win);
		string_put(opt, ft_itoa(opt->zoom));
		opt->zoom += 3;
		draw(opt->head, opt);
	}
	else if (opt->keycod == Z_DOWN && opt->iso == True)
	{
		opt->z -= 2;
		mlx_clear_window(opt->mlx, opt->win);
		draw(opt->head, opt);
	}
}

int		key_press(int keycod, t_option *opt)
{
	opt->keycod = keycod;
	if (keycod == ESC)
	{
		destroy_leaks(opt);
		mlx_destroy_window(opt->mlx, opt->win);
		exit(0);
	}
	else if (keycod == I_PRESSED || keycod == P_PRESSED)
		iso_para(opt);
	else if (keycod == ZOOM_IN || keycod == ZOOM_OUT || keycod == Z_DOWN)
		ft_zoom(opt);
	else if (keycod == M_PRESSED || keycod == X_PRESSED || keycod == Z_UP)
		manage_alpha(opt);
	else if (keycod >= 123 && keycod <= 126)
		manage_arrows(opt);
	else if (keycod == SPACE_PRESSED)
	{
		ft_option_init(opt, opt->mlx, opt->win);
		draw(opt->head, opt);
	}
	return (0);
}
