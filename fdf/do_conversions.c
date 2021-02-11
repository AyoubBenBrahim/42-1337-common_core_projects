/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:19:35 by aybouras          #+#    #+#             */
/*   Updated: 2019/07/13 19:41:45 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(int *x, int *y, int *z, t_option *opt)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	if (opt->iso == True)
	{
		*x = (previous_x - previous_y) * cos(0.523599);
		*y = ((previous_x + previous_y) * sin(0.523599)) - *z;
	}
	else
	{
		*y = previous_y - *z;
	}
}
