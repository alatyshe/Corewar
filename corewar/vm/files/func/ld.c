/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
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
			return (g_sizes[ps->cmd_in_hex][REG_CODE]);
		ft_putstr_fd("ERROR TYPE ARGUMENT T_REG get_type func\n", 2);
	}
	else if (type == DIR_CODE)
	{
		if (type & g_tab[ps->cmd_in_hex - 1].arg[argc])
			return (g_sizes[ps->cmd_in_hex][DIR_CODE]);
		ft_putstr_fd("ERROR TYPE ARGUMENT T_DIR get_type func\n", 2);
	}
	else if (type == IND_CODE)
	{
		if (type & g_tab[ps->cmd_in_hex - 1].arg[argc])
			return (g_sizes[ps->cmd_in_hex][IND_CODE]);
		ft_putstr_fd("ERROR TYPE ARGUMENT T_IND get_type func\n", 2);
	}
	else
		ft_putstr_fd("ERROR get_type func\n", 2);
	return (0);
}


int				get_value_map(t_map *all_info, t_ps *ps, int len)
{
	int			j;
	int			res;

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

int				get_length_arg(t_ps *ps, int argc)
{
	int			len;
	char		type;
	char		mask;

	len = 0;
	mask = 3;
	if (argc == 0)
		type = ((ps->codage_byte >> 6) & mask);
	else if (argc == 1)
		type = ((ps->codage_byte >> 4) & mask);
	else if (argc == 2)
		type = ((ps->codage_byte >> 2) & mask);
	len = get_type(ps, type, argc);
	return (len);
}

void			fill_args(t_map *all_info, t_player *player, t_ps *ps, int argc)
{
	int			len;

	len = 0;
	if (g_tab[ps->cmd_in_hex - 1].coding_byte == 1)
		len = get_length_arg(ps, argc);
	else
		len = g_sizes[ps->cmd_in_hex][DIR_CODE];
	ps->arg[argc] = get_value_map(all_info, ps, len);
}

// пока не работает

void			ld(t_map *all_info, t_player *player, t_ps *ps)
{
	int			i;
	int			arg;

	// ps->p_size = 5;
	if (ps->cycles_to_cmd < g_tab[0].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	ps->check_live = 1;
	
	printf("%sLD HAS BEEN USED BY:%s\n", GREEN, RESET);
	printf("%splayer:\t\t\t%d%s\n", GREEN, ps->player, RESET);
	printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	
	ps->cmd_in_hex = all_info->map[ps->pc];
	move_pc(ps, 1);
	ps->codage_byte = all_info->map[ps->pc];
	move_pc(ps, 1);
	while (arg < g_tab[ps->cmd_in_hex - 1].count_arg)
	{
		fill_args(all_info, player, ps, arg);
		arg++;
	}


	ps->cycles_to_cmd = 0;
}