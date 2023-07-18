/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:05:44 by ayb*****          #+#    #+#             */
/*   Updated: 2020/01/25 20:17:53 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	set_score(t_filler *f)
{
	int real_r;
	int real_c;

	real_r = f->m_r - f->p_r;
	real_c = (f->m_c - f->p_c) - 1;
	if (f->score < f->tstore.score)
	{
		f->tstore.row = real_r;
		f->tstore.col = real_c;
		f->tstore.score = f->score;
	}
}
