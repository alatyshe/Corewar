/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
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
	ps->cycles_to_cmd = 1;
}

void				move_map_counter(int *pos, int delta_pos)
{
	if (((*pos) + delta_pos) < MEM_SIZE)
		(*pos) += delta_pos;
	else
		(*pos) += delta_pos - MEM_SIZE;
}


// void				move_pc(t_ps *ps, int delta_pos)
// {
// 	if ((ps->pc + delta_pos) < MEM_SIZE)
// 		ps->pc += delta_pos;
// 	else
// 		ps->pc += delta_pos - MEM_SIZE;
// }

// int					exec_arg_value(char *map, t_ps *ps, int len)
// {
// 	int				value;

// 	value = 0;
// 	while (len)
// 	{
// 		value = value | map[ps->pc];
// 		len--;
// 		move_map_counter(&ps->pc, 1);
// 		if (len)
// 			value = value << 8;
// 	}
// 	return (value);
// }

unsigned int		get_value_from_file(void *buf, int len)
{
	int				j;
	unsigned int	res;

	j = 0;
	res = 0;
	while (j < len)
		res = (res << 8) | (((char *)buf)[j++] & 0x000000ff);
	return (res);
}

int					get_value_from_map(t_map *all_info, int *where, int len)
{
	int				j;
	int				res;

	j = 0;
	res = 0;
	while (j < len)
	{
		res = (res << 8) | (all_info->map[(*where)] & 0x000000ff);
		move_map_counter(where, 1);
		j++;
	}
	return (res);
}

void				write_value_on_map(t_map *all_info, int where, int value_in)
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
		all_info->map[where] = (value & 0x000000ff);
		move_map_counter(&where, 1);
	}
}

