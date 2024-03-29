/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:28:23 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/24 19:43:08 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Saves the fraction and decimal parts to different strings
*/

static void	save_parts(t_args *args, int mb_isset, int e)
{
	int		mtslen;

	mtslen = pf_strlen(args->mantiss);
	if (e < 0 && mb_isset)
	{
		e = pf_abs(mtslen - 63 + e);
		args->fract = padd(args->mantiss, e, '0', 'L');
		args->decimal = pf_strdup("0");
	}
	else
	{
		e = mtslen - 63;
		args->decimal = pf_strsub(args->mantiss, 0, e);
		args->fract = pf_strdup(args->mantiss + e);
	}
}

/*
**	Seperates the decimal and fraction parts of a float type
**	it stores them as a strings with the specified precision.
*/

void		split_float_parts(t_args *args)
{
	char				*tmp;
	int					e;
	int					mb_isset;
	struct s_floatbits	floatbits;

	floatbits = args->u_nion.floatbits;
	e = args->u_nion.floatbits.exponent - 16383;
	get_mantissa(args);
	mb_isset = floatbits.mantissa || floatbits.bit;
	if (mb_isset)
	{
		tmp = e < 0 ? pf_large_pow(pf_abs(e), "5") : \
						pf_large_pow(pf_abs(e), "2");
		args->mantiss = multiply_string(tmp, args->mantiss, 1);
	}
	save_parts(args, mb_isset, e);
	if (args->precision > (int)pf_strlen(args->fract))
	{
		tmp = args->fract;
		args->fract = padd(args->fract, args->precision + 1, '0', 'R');
		pf_strdel(&tmp);
	}
	pf_strdel(&args->mantiss);
}

/*
**	Joins '.' to the decimal part of a floating point number only
**	if '#' flag is given or there is a non null precision
*/

void		join_dot_to_decimal(t_args *args)
{
	if (args->decimal && args->fract)
	{
		if ((args->flag & MASK_HASH) || args->precision)
		{
			args->mantiss = pf_strjoin_free(args->decimal, pf_strdup("."));
			args->mantiss = pf_strjoin_free(args->mantiss, args->fract);
		}
		else
		{
			args->mantiss = pf_strdup(args->decimal);
			pf_strdel(&args->decimal);
			pf_strdel(&args->fract);
		}
		if (args->u_nion.floatbits.sign)
			args->mantiss = pf_strjoin_free(pf_strdup("-"), args->mantiss);
	}
}
