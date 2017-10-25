/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/10/24 16:18:08 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		print_flags_sti(t_map *map, t_ps *ps, int *value, int pc)
{
	int			res;

	if (check_flags(map->flags, 'v', 4))
	{
		res = value[SECOND_ARG] + value[THIRD_ARG];
		ft_printf("P%5d | %s r%d", ps->ps_num, "sti", ps->arg[0]);
		ft_printf(" %d %d\n       | -> store to", value[SECOND_ARG],
			value[THIRD_ARG]);
		ft_printf(" %d + %d = ", value[SECOND_ARG], value[THIRD_ARG]);
		ft_printf("%d (with pc and mod %d)\n", res, pc);
	}
}

static void		execute_sti_cmd(t_map *map, t_ps *ps)
{
	int			*value;
	int			distance;
	int			pc;
	int			i;

	i = -1;
	value = (int *)malloc(sizeof(int) * g_tab[10].count_arg);
	while (++i < g_tab[10].count_arg)
	{
		value[i] = get_variables_idxmod(map, ps, i);
		if (ps->skip_cmd)
		{
			ps->skip_cmd = 0;
			free(value);
			return ;
		}
	}
	pc = ps->pc;
	distance = (value[SECOND_ARG] + value[THIRD_ARG]) % IDX_MOD;
	move_map_counter(&pc, distance);
	write_value_on_map(map, pc, ps->reg[ps->arg[FIRST_ARG] - 1], ps);
	if (map->flags->java_flag)
		ft_printf(":%d:%d", pc, ps->reg[ps->arg[FIRST_ARG] - 1]);
	print_flags_sti(map, ps, value, ps->pc + distance);
	free(value);
}

int				cmd_sti(t_map *map, t_ps *ps)
{
	int			pc;
	int			temp_pc;
	int			stop_moving;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	stop_moving = ps->skip_cmd;
	if (ps->skip_cmd == 0)
		execute_sti_cmd(map, ps);
	print_v_flag_adv(map, ps, pc);
	ps->pc = pc;
	null_commands_variables(ps);
	return (stop_moving);
}
