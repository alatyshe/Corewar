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

int				get_type(t_ps *ps, char type, int argc)
{
	if (type == REG_CODE)
	{
		if (type & g_tab[ps->cmd_in_hex - 1].arg[argc])
		{
			ps->arg_types[argc] = REG_CODE;
			return (g_sizes[ps->cmd_in_hex][REG_CODE]);
		}
		ft_putstr_fd("ERROR TYPE ARGUMENT T_REG get_type func\n", 2);
	}
	else if (type == DIR_CODE)
	{
		if (type & g_tab[ps->cmd_in_hex - 1].arg[argc])
		{
			ps->arg_types[argc] = DIR_CODE;
			return (g_sizes[ps->cmd_in_hex][DIR_CODE]);
		}
		ft_putstr_fd("ERROR TYPE ARGUMENT T_DIR get_type func\n", 2);
	}
	else if (type == IND_CODE)
	{
		if (type & g_tab[ps->cmd_in_hex - 1].arg[argc])
		{
			ps->arg_types[argc] = IND_CODE;
			return (g_sizes[ps->cmd_in_hex][IND_CODE]);
		}
		ft_putstr_fd("ERROR TYPE ARGUMENT T_IND get_type func\n", 2);
	}
	else
		ft_putstr_fd("ERROR get_type func\n", 2);
	return (0);
}


static int		get_value_from_map(t_map *all_info, t_ps *ps, int len)
{
	int			j;
	int			res;
	int			position;

	j = 0;
	res = 0;
	while (j < len)
	{
		res = (res << 8) | (all_info->map[ps->pc] & 0x000000ff);
		move_pc(ps, 1);
		j++;
	}
	return (res);
}

int				get_value_from_map_2(t_map *all_info, t_ps *ps, int pos, int len)
{
	int			j;
	int			res;
	int			position;

	j = 0;
	res = 0;
	position = move_counter(ps->pc - ps->p_size, pos);
	while (j < len)
	{
		res = (res << 8) | (all_info->map[position] & 0x000000ff);
		position = move_counter(position, 1);
		j++;
	}
	return (res);
}

int				get_length_arg(t_ps *ps, int argc)
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
	len = get_type(ps, type, argc);
	ps->p_size += len;
	return (len);
}

void			fill_args(t_map *all_info, t_ps *ps, int argc)
{
	int			len;

	len = 0;
	if (g_tab[ps->cmd_in_hex - 1].coding_byte == 1)
		len = get_length_arg(ps, argc);
	else
		len = g_sizes[ps->cmd_in_hex][DIR_CODE];
	ps->arg[argc] = get_value_from_map(all_info, ps, len);
}

void			fill_commands(t_map *all_info, t_ps *ps)
{
	int			arg;

	arg = 0;
	ps->cmd_in_hex = all_info->map[ps->pc];
	move_pc(ps, 1);
	ps->p_size++;
	if (arg < g_tab[ps->cmd_in_hex - 1].coding_byte)
	{
		ps->p_size++;
		ps->coding_byte = all_info->map[ps->pc];
		move_pc(ps, 1);
	}
	while (arg < g_tab[ps->cmd_in_hex - 1].count_arg)
	{
		fill_args(all_info, ps, arg);
		arg++;
	}
}

void			null_commands_variables(t_ps *ps)
{
	int			i;

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
}
