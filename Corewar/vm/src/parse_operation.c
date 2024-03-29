/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitihia <aaitihia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:01:45 by ayb*****          #+#    #+#             */
/*   Updated: 2021/03/31 13:39:52 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

char			get_arg_code(int args_code, int arg_num)
{
	char arg;

	arg = (args_code >> (6 - arg_num * 2)) & 3;
	return (arg + (arg == 3));
}

static int		get_tind(t_vm *vm, t_cursor *prc, int pc)
{
	int	addr;

	addr = get_mem(vm->colosseum, pc, 2);
	if (prc->cmp.code == OP_ST)
		return (addr);
	if (g_op_tab[prc->cmp.code].mod)
		return (get_mem(vm->colosseum, prc->cur_addr + idx_mod(addr), 4));
	else
		return (get_mem(vm->colosseum, prc->cur_addr + addr, 4));
}

static int		get_pc(t_cursor *prc)
{
	return (addr_overlap(prc->cur_addr + prc->cmp.step));
}

static int		get_arg(t_vm *vm, t_cursor *prc, int code)
{
	int i;
	int ac;

	i = 0;
	while (i < g_op_tab[code].arg_num)
	{
		ac = get_arg_code(prc->cmp.arg_code, i);
		if ((g_op_tab[code].arg[i] & ac) == 0)
			return (FALSE);
		if (ac == T_DIR)
			prc->cmp.arg[i] = get_mem(vm->colosseum, get_pc(prc),
													g_op_tab[code].size_dir);
		else if (ac == T_IND)
			prc->cmp.arg[i] = get_tind(vm, prc, get_pc(prc));
		else if (ac == T_REG && between(vm->colosseum[get_pc(prc)], 1, 16))
			prc->cmp.arg[i] = vm->colosseum[get_pc(prc)];
		else
			return (FALSE);
		prc->cmp.step += (ac != T_DIR ? 1 + (ac == 4) :
													g_op_tab[code].size_dir);
		i++;
	}
	return (TRUE);
}

t_boolean		parse_operation(t_vm *vm, t_cursor *prc)
{
	if (!g_op_tab[prc->cmp.code].arg_code)
	{
		prc->cmp.step = 1 + g_op_tab[prc->cmp.code].size_dir;
		prc->cmp.arg[0] = get_mem(vm->colosseum, prc->cur_addr + 1,
											g_op_tab[prc->cmp.code].size_dir);
		return (TRUE);
	}
	prc->cmp.arg_code = vm->colosseum[addr_overlap(prc->cur_addr + 1)];
	prc->cmp.step = 2;
	return (get_arg(vm, prc, prc->cmp.code));
}
