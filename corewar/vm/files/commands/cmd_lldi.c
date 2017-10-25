/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		print_flags_ldi(t_map *map, t_ps *ps,
	int *value, int pc)
{
	if (check_flags(map->flags, 'v', 4))
	{
		ft_printf("P%5d | %s %d %d r%d\n", ps->ps_num,
			"lldi", value[FIRST_ARG], value[SECOND_ARG], ps->arg[2]);
		ft_printf("       | -> load from %d + %d = %d", value[FIRST_ARG],
			value[SECOND_ARG], value[FIRST_ARG] + value[SECOND_ARG]);
		ft_printf(" (with pc and mod %d)\n", pc);
	}
}

static void		execute_lldi_cmd(t_map *map, t_ps *ps)
{
	int			*value;
	int			distance;
	int			pc;
	int			i;

	i = 0;
	value = (int *)malloc(sizeof(int) * g_tab[9].count_arg);
	while (i < g_tab[9].count_arg)
	{
		value[i] = get_variables(map, ps, i);
		if (ps->skip_cmd)
		{
			ps->skip_cmd = 0;
			free(value);
			return ;
		}
		i++;
	}
	distance = (value[FIRST_ARG] + value[SECOND_ARG]) % IDX_MOD;
	pc = ps->pc;
	move_map_counter(&pc, distance);
	print_flags_ldi(map, ps, value, pc);
	ps->reg[ps->arg[THIRD_ARG] - 1] = get_value_from_map(map, &pc, 4);
	free(value);
}

int				cmd_lldi(t_map *map, t_ps *ps)
{
	int			pc;
	int			temp_pc;
	int			stop_moving;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	stop_moving = ps->skip_cmd;
	if (ps->skip_cmd == 0)
		execute_lldi_cmd(map, ps);
	if (check_flags(map->flags, 'v', 16))
	{
		if (ps->pc == 0)
			ft_printf("ADV %d (0x0000 -> %#06x) ", pc - ps->pc, pc);
		else
			ft_printf("ADV %d (%#06x -> %#06x) ", pc - ps->pc, ps->pc, pc);
		while (temp_pc != pc)
		{
			ft_printf("%02x ", map->map[temp_pc] & 255);
			move_map_counter(&temp_pc, 1);
		}
		ft_printf("\n");
	}
	ps->pc = pc;
	null_commands_variables(ps);
	return (stop_moving);
}
