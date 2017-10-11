/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_lldi_cmd(t_map *all_info, t_ps *ps);

//	проверки на валидность нет и пропус команды
void			lldi(t_map *all_info, t_player *player, t_ps *ps)
{
	int			i;
	int			pc;

	if (ps->cycles_to_cmd < g_tab[13].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	
	printf("%sLLDI HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%splayer:\t\t\t%d%s\n", GREEN, ps->player, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(all_info, ps);
	execute_lldi_cmd(all_info, ps);
	ps->pc = pc;

	print_process(ps);
	null_commands_variables(ps);
}

static void		execute_lldi_cmd(t_map *all_info, t_ps *ps)
{
	int			first_arg;
	int			second_arg;
	int			distance;
	int			res;
	int			pc;

	//	проверка 1-го аргумента
	if (ps->arg_types[FIRST_ARG] == REG_CODE)
	{
		if (ps->arg[FIRST_ARG] < 1
			|| ps->arg[FIRST_ARG] > 16)
			return ;
		first_arg = ps->reg[ps->arg[FIRST_ARG] - 1];
	}
	else if (ps->arg_types[FIRST_ARG] == DIR_CODE)
		first_arg = ps->arg[FIRST_ARG];
	else if (ps->arg_types[FIRST_ARG] == IND_CODE)
	{
		pc = ps->pc;
		distance = ps->arg[FIRST_ARG];
		move_map_counter(&pc, distance);
		first_arg = get_value_from_map(all_info, &pc, 4);
	}
	//	проверка 2-го аргумента
	if (ps->arg_types[SECOND_ARG] == REG_CODE)
	{
		if (ps->arg[SECOND_ARG] < 1
			|| ps->arg[SECOND_ARG] > 16)
			return ;
		second_arg = ps->reg[ps->arg[SECOND_ARG] - 1];
	}
	else if (ps->arg_types[SECOND_ARG] == DIR_CODE)
		second_arg = ps->arg[SECOND_ARG];
	//	проверка 3-го аргумента
	if (ps->arg[THIRD_ARG] < 1
		|| ps->arg[THIRD_ARG] > 16)
		return ;

	// аргуметы есть
}