/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:35:34 by ayb*****          #+#    #+#             */
/*   Updated: 2020/01/25 20:16:55 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	int bool;

	bool = (c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\f' || c == '\r') ? 1 : 0;
	return (bool);
}
