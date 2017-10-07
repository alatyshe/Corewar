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

// пока не работает

static void		execute_ld_cmd(t_map *all_info, t_ps *ps)
{
	printf("AAAAA\n");
	if(ps->arg_types[0] == DIR_CODE)
	{
		ps->reg[ps->arg_types[1]] = ps->arg[0];
		
	}
	else
		ps->reg[ps->arg_types[1]] = get_value_from_map_2(all_info, ps, ps->arg[0], 4);
}

void			ld(t_map *all_info, t_player *player, t_ps *ps)
{
	int			i;

	// ps->p_size = 5;
	if (ps->cycles_to_cmd < g_tab[0].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	ps->check_live = 1;
	
	printf("%sLD HAS BEEN USED BY:%s\n", GREEN, RESET);
	printf("%splayer:\t\t\t%d%s\n", GREEN, ps->player, RESET);
	printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	
	print_process(ps);

	fill_commands(all_info, ps);
	execute_ld_cmd(all_info, ps);

	print_process(ps);
	
	null_commands_variables(ps);
	ps->cycles_to_cmd = 0;
}