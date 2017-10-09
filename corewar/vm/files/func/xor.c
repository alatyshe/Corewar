/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_xor_cmd(t_map *all_info, t_ps *ps);

//	проверки на валидность нет и пропус команды CARRY НЕ МЕНЯЕТ
void			xor(t_map *all_info, t_player *player, t_ps *ps)
{
	int			i;
	int			pc;

	if (ps->cycles_to_cmd < g_tab[7].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	
	printf("%sXOR HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%splayer:\t\t\t%d%s\n", GREEN, ps->player, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(all_info, ps);
	execute_xor_cmd(all_info, ps);
	ps->pc = pc;

	// print_process(ps);
	null_commands_variables(ps);
}

static void		execute_xor_cmd(t_map *all_info, t_ps *ps)
{
	int			first_arg;
	int			second_arg;
	int			pc;

	if (ps->arg_types[FIRST_ARG] == REG_CODE)
		first_arg = ps->reg[ps->arg[FIRST_ARG] - 1];
	else if (ps->arg_types[FIRST_ARG] == DIR_CODE)
		first_arg = ps->arg[FIRST_ARG];
	else if (ps->arg_types[FIRST_ARG] == IND_CODE)
		pc = ps->pc + ps->arg[FIRST_ARG];
		first_arg = get_value_from_map(all_info, &pc, 4);
	if (ps->arg_types[SECOND_ARG] == REG_CODE)
		second_arg = ps->reg[ps->arg[SECOND_ARG] - 1];
	else if (ps->arg_types[SECOND_ARG] == DIR_CODE)
		second_arg = ps->arg[SECOND_ARG];
	else if (ps->arg_types[SECOND_ARG] == IND_CODE)
	{
		pc = ps->pc + ps->arg[SECOND_ARG];
		second_arg = get_value_from_map(all_info, &pc, 4);
	}
	ps->reg[ps->arg[THIRD_ARG] - 1] = first_arg ^ second_arg;
}

