/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_ld_cmd(t_map *map, t_ps *ps);

void			cmd_ld(t_map *map, t_ps *ps)
{
	int			pc;
	int			temp_pc;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	if (ps->skip_cmd == 0)
		execute_ld_cmd(map, ps);
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

static void		execute_ld_cmd(t_map *map, t_ps *ps)
{
	int			pc;
	int			distance;
	int			first_arg;

	if (ps->arg[SECOND_ARG] < 1
		|| ps->arg[SECOND_ARG] > 16)
		return ;
	if (ps->arg_types[FIRST_ARG] == DIR_CODE)
		first_arg = ps->arg[FIRST_ARG];
	else
	{
		pc = ps->pc;
		distance = ps->arg[FIRST_ARG] % IDX_MOD;
		move_map_counter(&pc, distance);
		first_arg = get_value_from_map(map, &pc, 4);
	}
	if (first_arg == 0)
		ps->carry = 1;
	else
		ps->carry = 0;
	ps->reg[ps->arg[1] - 1] = first_arg;
	if (check_flags(map->flags, 'v', 4))
		ft_printf("P    %-d | %s %d r%d\n", ps->ps_num, "ld", first_arg, ps->arg[1]);
}
