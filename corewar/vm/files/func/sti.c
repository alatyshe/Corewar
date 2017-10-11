/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_sti_cmd(t_map *all_info, t_ps *ps);

void			sti(t_map *all_info, t_player *player, t_ps *ps)
{
	int			i;
	int			pc;

	if (ps->cycles_to_cmd < g_tab[10].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	
	printf("%sSTI HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%splayer:\t\t\t%d%s\n", GREEN, ps->player, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(all_info, ps);
	execute_sti_cmd(all_info, ps);
	ps->pc = pc;

	// print_process(ps);
	null_commands_variables(ps);
}

static void		execute_sti_cmd(t_map *all_info, t_ps *ps)
{
	int			first_arg;
	int			second_arg;
	int			third_arg;
	int			distance;
	int			res;
	int			pc;

	//	first argument
	if (ps->arg[FIRST_ARG] < 1
		|| ps->arg[FIRST_ARG] > 16)
		return ;
	first_arg = ps->reg[ps->arg[FIRST_ARG] - 1];
	//	second argument
	if (ps->arg_types[SECOND_ARG] == REG_CODE)
	{
		if (ps->arg[SECOND_ARG] < 1
			|| ps->arg[SECOND_ARG] > 16)
			return ;
		second_arg = ps->reg[ps->arg[SECOND_ARG] - 1];
	}
	else if (ps->arg_types[SECOND_ARG] == DIR_CODE)
		second_arg = ps->arg[SECOND_ARG];
	else if (ps->arg_types[SECOND_ARG] == IND_CODE)
	{
		pc = ps->pc;
		distance = ps->arg[SECOND_ARG] % IDX_MOD;
		move_map_counter(&pc, distance);
		second_arg = get_value_from_map(all_info, &pc, 4);
		printf("%x\n", second_arg);
	}
	//	third argument
	if (ps->arg_types[THIRD_ARG] == REG_CODE)
	{
		if (ps->arg[THIRD_ARG] < 1
			|| ps->arg[THIRD_ARG] > 16)
			return ;
		third_arg = ps->reg[ps->arg[THIRD_ARG] - 1];
	}
	else if (ps->arg_types[THIRD_ARG] == DIR_CODE)
		third_arg = ps->arg[THIRD_ARG];

	pc = ps->pc;
	distance = (second_arg + third_arg) % IDX_MOD;
	move_map_counter(&pc, distance);
	write_value_on_map(all_info, pc, ps->reg[ps->arg[FIRST_ARG] - 1]);
	
}
