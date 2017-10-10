/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"
//	CARRY GOOD!!!!!!!!!!!!!!!!!!!!!!!
static void		execute_ld_cmd(t_map *all_info, t_ps *ps);

//	проверки на валидность нет и пропус команды
void			ld(t_map *all_info, t_player *player, t_ps *ps)
{
	int			i;
	int			pc;

	if (ps->cycles_to_cmd < g_tab[1].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	
	printf("%sLD HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%splayer:\t\t\t%d%s\n", GREEN, ps->player, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(all_info, ps);
	execute_ld_cmd(all_info, ps);
	ps->pc = pc;

	print_process(ps);
	null_commands_variables(ps);
}

static void		execute_ld_cmd(t_map *all_info, t_ps *ps)
{
	int			pc;
	int			value;

	pc = ps->pc + ps->arg[FIRST_ARG];
	if(ps->arg_types[0] == DIR_CODE)
		value = ps->arg[0];
	else
		value = get_value_from_map(all_info, &pc, 4);
	if (value == 0)
		ps->carry = 1;
	else
		ps->carry = 0;
	ps->reg[ps->arg[1] - 1] = value;
}
