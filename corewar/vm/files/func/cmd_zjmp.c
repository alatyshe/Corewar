/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_zjmp_cmd(t_map *map, t_ps *ps);

void			cmd_zjmp(t_map *map, t_ps *ps)
{
	int			pc;
	int			temp_pc;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	if (ps->skip_cmd == 0)
		execute_zjmp_cmd(map, ps);

	if (check_flags(map->flags, 'v', 16) && ps->carry != 1)
	{
		if (ps->pc == 0)
			ft_printf("ADV %d (0x0000 -> %#06x) ", pc - temp_pc, pc);
		else
			ft_printf("ADV %d (%#06x -> %#06x) ", pc - temp_pc, ps->pc, pc);
		while (temp_pc != pc)
		{
			printf("%02x ", map->map[temp_pc] & 255);
			move_map_counter(&temp_pc, 1);
		}
		printf("\n");
	}



	null_commands_variables(ps);
}

static void		execute_zjmp_cmd(t_map *map, t_ps *ps)
{
	int			distance;
	int			pc;

	
	if (ps->carry == 1)
	{
		pc = ps->pc;
		distance = ps->arg[FIRST_ARG] % IDX_MOD;
		move_map_counter(&pc, distance);
		ps->pc = pc;
	}
	else
	{
		pc = ps->pc;
		distance = 3;
		move_map_counter(&pc, distance);
		ps->pc = pc;
	}
	if (check_flags(map->flags, 'v', 4))
	{
		ft_printf("P    %-d | %s %d ", ps->ps_num, "zjmp", ps->arg[0]);
		if (ps->carry == 1)
			ft_printf("OK\n");
		else
			ft_printf("FAILED\n");
	}	
}
