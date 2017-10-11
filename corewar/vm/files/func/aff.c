/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_aff_cmd(t_map *all_info, t_ps *ps);

//	проверки на валидность нет и пропус команды
void			aff(t_map *all_info, t_player *player, t_ps *ps)
{
	int			i;
	int			pc;

	if (ps->cycles_to_cmd < g_tab[15].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	
	printf("%sAFF HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%splayer:\t\t\t%d%s\n", GREEN, ps->player, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(all_info, ps);
	execute_aff_cmd(all_info, ps);
	ps->pc = pc;

	print_process(ps);
	null_commands_variables(ps);
}

static void		execute_aff_cmd(t_map *all_info, t_ps *ps)
{

	// НЕ РАБОТАЕТ (аргуметы есть)
	// res = first_arg + second_arg;
	// ps->reg[ps->arg[THIRD_ARG] - 1] = res;
}
