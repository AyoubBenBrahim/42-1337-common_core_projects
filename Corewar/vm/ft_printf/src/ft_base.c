/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 08:27:13 by ayb*****          #+#    #+#             */
/*   Updated: 2019/11/24 19:43:29 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*to_binary(t_ull nbr)
{
	char	*convert;
	int		shift;
	int		mask;

	mask = 1;
	shift = 1;
	shipf_bits(&convert, nbr, mask, shift);
	return (convert);
}

static char	*to_hexa(t_ull nbr, char spec)
{
	int		shift;
	int		mask;
	char	*convert;

	mask = 15;
	shift = 4;
	shipf_bits(&convert, nbr, mask, shift);
	if (spec == 'X')
		pf_strupper(convert);
	return (convert);
}

static char	*to_octa(t_ull nbr)
{
	int		shift;
	int		mask;
	char	*convert;

	mask = 7;
	shift = 3;
	shipf_bits(&convert, nbr, mask, shift);
	return (convert);
}

/*
 **	Converts the given number passed as first parameter
 ** to the appropriate base according to specifier (poubxX)
*/

char		*pf_base(t_args *args)
{
	if (args->spec == 'u')
		return (pf_utoa(args->unsign_ed));
	else if (args->spec == 'b')
		return (to_binary(args->unsign_ed));
	else if (args->spec == 'o')
		return (to_octa(args->unsign_ed));
	else if (args->spec == 'x' || args->spec == 'X' || args->spec == 'p')
		return (to_hexa(args->unsign_ed, args->spec));
	return (NULL);
}
