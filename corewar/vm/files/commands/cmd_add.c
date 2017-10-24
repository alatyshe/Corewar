/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		print_flags_add(t_map *map, t_ps *ps)
{
	if (check_flags(map->flags, 'v', 4))
	{
		ft_printf("P%5d | %s ", ps->ps_num, "add");
		ft_printf("r%d r%d r%d\n", ps->arg[0], ps->arg[1], ps->arg[2]);
	}
}

static void		execute_add_cmd(t_map *map, t_ps *ps)
{
	int			*value;
	int			res;
	int			i;

	i = 0;
	value = (int *)malloc(sizeof(int) * g_tab[3].count_arg);
	while (i < g_tab[3].count_arg)
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
	res = value[FIRST_ARG] + value[SECOND_ARG];
	if (!res)
		ps->carry = 1;
	else
		ps->carry = 0;
	ps->reg[ps->arg[THIRD_ARG] - 1] = res;
	print_flags_add(map, ps);
	free(value);
}

int				cmd_add(t_map *map, t_ps *ps)
{
	int			pc;
	int			temp_pc;
	int			stop_moving;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	stop_moving = ps->skip_cmd;
	if (ps->skip_cmd == 0)
		execute_add_cmd(map, ps);
	print_v_flag_adv(map, ps, pc);
	ps->pc = pc;
	null_commands_variables(ps);
	return (stop_moving);
}
