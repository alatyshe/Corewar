/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/10/24 16:17:53 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		print_flags_st(t_map *map, t_ps *ps)
{
	if (check_flags(map->flags, 'v', 4))
	{
		ft_printf("P%5d | %s r%d %d\n", ps->ps_num,
			"st", ps->arg[0], ps->arg[1]);
	}
}

static void		execute_st_cmd(t_map *map, t_ps *ps)
{
	int			second_arg;
	int			first_arg;
	int			distance;
	int			pc;

	first_arg = ps->arg[FIRST_ARG];
	second_arg = ps->arg[SECOND_ARG];
	if (first_arg < 1 || first_arg > 16)
		return ;
	if (ps->arg_types[SECOND_ARG] == REG_CODE)
	{
		if (second_arg < 1 || second_arg > 16)
			return ;
		ps->reg[second_arg - 1] = ps->reg[first_arg - 1];
	}
	else
	{
		pc = ps->pc;
		distance = second_arg % IDX_MOD;
		move_map_counter(&pc, distance);
		write_value_on_map(map, pc, ps->reg[first_arg - 1], ps);
		if (map->flags->java_flag)
			ft_printf(":%d:%d", pc, ps->reg[first_arg - 1]);
	}
	print_flags_st(map, ps);
}

int				cmd_st(t_map *map, t_ps *ps)
{
	int			pc;
	int			temp_pc;
	int			stop_moving;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	stop_moving = ps->skip_cmd;
	if (ps->skip_cmd == 0)
		execute_st_cmd(map, ps);
	print_v_flag_adv(map, ps, pc);
	ps->pc = pc;
	null_commands_variables(ps);
	return (stop_moving);
}
