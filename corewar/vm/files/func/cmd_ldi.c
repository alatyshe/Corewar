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

static void		execute_ldi_cmd(t_map *all_info, t_ps *ps);

void			cmd_ldi(t_map *all_info, t_ps *ps)
{
	int			pc;

	if (ps->cycles_to_cmd < g_tab[9].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	
	printf("%sLDI HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(all_info, ps);
	execute_ldi_cmd(all_info, ps);
	ps->pc = pc;

	// print_process(ps);
	null_commands_variables(ps);
}

static void		execute_ldi_cmd(t_map *all_info, t_ps *ps)
{
	int			value[g_tab[3].count_arg];
	int			distance;
	int			pc;
	int			i;

	i = 0;
	while (i < g_tab[3].count_arg)
	{
		value[i] = get_variables_idxmod(all_info, ps, i, g_tab[3].arg[i]);
		if (ps->skip_cmd)
		{
			ps->skip_cmd = 0;
			return ;
		}
		i++;
	}
	distance = (value[FIRST_ARG] + value[SECOND_ARG]) % IDX_MOD;
	pc = ps->pc;
	move_map_counter(&pc, distance);
	ps->reg[ps->arg[THIRD_ARG] - 1] = get_value_from_map(all_info, &pc, 4);
}

