/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:14:59 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/03/31 13:19:40 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	op_or(t_cursor *prc, t_op_component *cmp, t_vm *vm)
{
	const int arg1_is_register = get_arg_code(cmp->arg_code, 0) == T_REG;
	const int arg2_is_register = get_arg_code(cmp->arg_code, 1) == T_REG;

	cmp->arg[0] = arg1_is_register ? prc->reg[cmp->arg[0]] : cmp->arg[0];
	cmp->arg[1] = arg2_is_register ? prc->reg[cmp->arg[1]] : cmp->arg[1];
	(void)vm;
	prc->reg[cmp->arg[2]] = cmp->arg[0] | cmp->arg[1];
	prc->carry = prc->reg[cmp->arg[2]] == 0;
}
