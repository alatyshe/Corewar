/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/10/24 16:16:43 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

void				null_commands_variables(t_ps *ps)
{
	int				i;

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		ps->arg_types[i] = 0;
		ps->arg[i] = 0;
		i++;
	}
	ps->cmd_in_hex = 0;
	ps->coding_byte = 0;
	ps->p_size = 0;
	ps->cycles_to_cmd = 0;
	ps->skip_cmd = 0;
}

void				move_map_counter(int *pos, int delta_pos)
{
	if (delta_pos > MEM_SIZE - 1 || delta_pos < -MEM_SIZE + 1)
		delta_pos = delta_pos % (MEM_SIZE - 1);
	if (((*pos) + delta_pos) < 0)
		(*pos) = MEM_SIZE + ((*pos) + delta_pos);
	else if (((*pos) + delta_pos) < MEM_SIZE)
		(*pos) += delta_pos;
	else
		(*pos) += delta_pos - MEM_SIZE;
}

int					get_value_from_map(t_map *map, int *where, int len)
{
	int				j;
	int				res;

	j = 0;
	res = 0;
	while (j < len)
	{
		res = (res << 8) | (map->map[(*where)] & 0x000000ff);
		move_map_counter(where, 1);
		j++;
	}
	if (len == 2 && res & 0x8000)
		res = (short)res;
	return (res);
}

void				write_value_on_map(t_map *map, int where,
	int value_in, t_ps *ps)
{
	int				j;
	int				i;
	int				value;

	j = 4;
	while (j)
	{
		j--;
		i = 0;
		value = value_in;
		while (i < j)
		{
			i++;
			value = value >> 8;
		}
		map->map[where] = (value & 0x000000ff);
		if (map->flags->n_flag)
			put_on_map(where, ps->player_num * -1, map->map, map->clr);
		move_map_counter(&where, 1);
	}
}

void				copy_process(t_ps *ps, t_ps *ps_new)
{
	int				i;

	i = 0;
	ps_new->player_num = ps->player_num;
	ps_new->check_live = ps->check_live;
	ps_new->carry = ps->carry;
	while (i < 16)
	{
		ps_new->reg[i] = ps->reg[i];
		i++;
	}
}
