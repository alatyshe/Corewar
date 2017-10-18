/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static int		get_type(t_ps *ps, char type, int argc)
{
	if (type == REG_CODE
		&& (T_REG & g_tab[(int)ps->cmd_in_hex - 1].arg[argc]))
		ps->arg_types[argc] = T_REG;
	else if (type == DIR_CODE
		&& (T_DIR & g_tab[(int)ps->cmd_in_hex - 1].arg[argc]))
		ps->arg_types[argc] = T_DIR;
	else if (type == IND_CODE
		&& (T_IND & g_tab[(int)ps->cmd_in_hex - 1].arg[argc]))
		ps->arg_types[argc] = T_IND;
	else
		ps->skip_cmd = 1;
	return (g_sizes[(int)ps->cmd_in_hex][(int)type]);
}

static int		get_length_arg(t_ps *ps, int argc)
{
	int			len;
	char		type;
	char		mask;

	len = 0;
	mask = 3;
	if (argc == 0)
		type = ((ps->coding_byte >> 6) & mask);
	else if (argc == 1)
		type = ((ps->coding_byte >> 4) & mask);
	else if (argc == 2)
		type = ((ps->coding_byte >> 2) & mask);
	else
		type = (ps->coding_byte & mask);
	len = get_type(ps, type, argc);
	ps->p_size += len;
	return (len);
}

static void		fill_args(t_map *all_info, t_ps *ps, int *pc_copy, int argc)
{
	int			len;

	len = 0;
	if (g_tab[ps->cmd_in_hex - 1].coding_byte == 1)
		len = get_length_arg(ps, argc);
	else
	{
		len = g_sizes[(int)ps->cmd_in_hex][DIR_CODE];
		ps->p_size += 4;
	}
	ps->arg[argc] = get_value_from_map(all_info, pc_copy, len);
}

int				fill_commands(t_map *all_info, t_ps *ps)
{
	int			arg;
	int			pc_copy;

	arg = 0;
	pc_copy = ps->pc;
	move_map_counter(&pc_copy, 1);
	ps->p_size++;
	if (arg < g_tab[ps->cmd_in_hex - 1].coding_byte)
	{
		ps->p_size++;
		ps->coding_byte = all_info->map[pc_copy];
		move_map_counter(&pc_copy, 1);
	}
	while (arg < g_tab[ps->cmd_in_hex - 1].count_arg)
	{
		fill_args(all_info, ps, &pc_copy, arg);
		arg++;
	}
	return (pc_copy);
}
