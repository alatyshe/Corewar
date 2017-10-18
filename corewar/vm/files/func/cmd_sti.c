/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_sti_cmd(t_map *map, t_ps *ps);

void			cmd_sti(t_map *map, t_ps *ps)
{
	int			pc;
	int			temp_pc;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	if (ps->skip_cmd == 0)
		execute_sti_cmd(map, ps);	

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

static void		execute_sti_cmd(t_map *map, t_ps *ps)
{
	int			*value;
	int			distance;
	int			pc;
	int			i;

	i = 0;
	value = (int *)malloc(sizeof(int) * g_tab[10].count_arg);
	while (i < g_tab[10].count_arg)
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
	pc = ps->pc;
	distance = (value[SECOND_ARG] + value[THIRD_ARG]) % IDX_MOD;
	move_map_counter(&pc, distance);
	// printf("CHANGE VALUE ON MAP AT Y : %d, X : %d\n", pc / 64, pc % 64);
	// printf("VALUE : %08x\n", ps->reg[ps->arg[FIRST_ARG] - 1]);
	write_value_on_map(map, ps, pc, ps->reg[ps->arg[FIRST_ARG] - 1]);
	if (map->flags->java_flag)
		ft_printf(":%d:%d", pc, ps->reg[ps->arg[FIRST_ARG] - 1]);
	if (check_flags(map->flags, 'v', 4))
		ft_printf("P    %-d | %s r%d %d %d\n       | -> store to %d + %d = %d (with pc and mod %d)\n", ps->ps_num, "sti", ps->arg[0], value[SECOND_ARG], value[THIRD_ARG], value[SECOND_ARG], value[THIRD_ARG], value[SECOND_ARG] + value[THIRD_ARG], pc);
	free(value);
}