/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_ldi_cmd(t_map *map, t_ps *ps);

void			cmd_ldi(t_map *map, t_ps *ps)
{
	int			pc;
	int			temp_pc;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	if (ps->skip_cmd == 0)
		execute_ldi_cmd(map, ps);

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

static void		execute_ldi_cmd(t_map *map, t_ps *ps)
{
	int			*value;
	int			distance;
	int			pc;
	int			i;

	i = 0;
	value = (int *)malloc(sizeof(int) * g_tab[9].count_arg);
	while (i < g_tab[9].count_arg)
	{
		value[i] = get_variables_idxmod(map, ps, i);
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
	if (check_flags(map->flags, 'v', 4))
	{
		ft_printf("P    %-d | %s %d %d r%d\n", ps->ps_num, "ldi", value[FIRST_ARG], value[SECOND_ARG], ps->arg[2]);
		ft_printf("       | -> load from %d + %d = %d", value[FIRST_ARG], value[SECOND_ARG], value[FIRST_ARG] + value[SECOND_ARG]);
		ft_printf(" (with pc and mod %d)\n", pc);
	}
	ps->reg[ps->arg[THIRD_ARG] - 1] = get_value_from_map(map, &pc, 4);
	free(value);
}
