/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_st_cmd(t_map *map, t_ps *ps);

void			cmd_st(t_map *map, t_ps *ps)
{
	int			pc;
	int			temp_pc;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	if (ps->skip_cmd == 0)
		execute_st_cmd(map, ps);

	if (check_flags(map->flags, 'v', 16))
	{
		if (ps->pc == 0)
			ft_printf("ADV %d (0x0000 -> %#06x) ", pc - ps->pc, pc);
		else
			ft_printf("ADV %d (%#06x -> %#06x) ", pc - ps->pc, ps->pc, pc);
		while (temp_pc != pc)
		{
			printf("%02x ", map->map[temp_pc] & 255);
			move_map_counter(&temp_pc, 1);
		}
		printf("\n");
	}

	ps->pc = pc;

	null_commands_variables(ps);
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
	if(ps->arg_types[SECOND_ARG] == REG_CODE)
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
		write_value_on_map(map, pc, ps->reg[first_arg - 1]);
		if (map->flags->java_flag)
			ft_printf("|%d:%d", pc, ps->reg[first_arg - 1]);
	}
	if (check_flags(map->flags, 'v', 4))
		ft_printf("P    %-d | %s r%d %d\n", ps->ps_num, "st", ps->arg[0], ps->arg[1]);
}
