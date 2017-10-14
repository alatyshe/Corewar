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

static void		execute_zjmp_cmd(t_ps *ps);

void			cmd_zjmp(t_map *all_info, t_ps *ps)
{
	int			pc;

	if (ps->cycles_to_cmd < g_tab[8].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}

	printf("%sZJMP HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(all_info, ps);
	execute_zjmp_cmd(ps);

	// print_process(ps);
	null_commands_variables(ps);
}

static void		execute_zjmp_cmd(t_ps *ps)
{
	int			distance;
	int			pc;

	if (ps->carry == 1)
	{
		pc = ps->pc;
		distance = ps->arg[SECOND_ARG] % IDX_MOD;
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
}
