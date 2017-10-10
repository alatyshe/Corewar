/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

// static void		execute_fork_cmd(t_map *all_info, t_ps *ps);

// void			fork(t_map *all_info, t_player *player, t_ps *ps)
// {
// 	int			i;
// 	int			pc;

// 	if (ps->cycles_to_cmd < g_tab[12].cycle)
// 	{
// 		ps->cycles_to_cmd++;
// 		return ;
// 	}
	
// 	printf("%sFORK HAS BEEN USED BY:%s\n", GREEN, RESET);
// 	// printf("%splayer:\t\t\t%d%s\n", GREEN, ps->player, RESET);
// 	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
// 	// print_process(ps);

// 	pc = fill_commands(all_info, ps);
// 	execute_fork_cmd(all_info, ps);

// 	// print_process(ps);
// 	null_commands_variables(ps);
// }

// void			copy_process(t_map *all_info, t_ps *ps)
// {
// 	t_player	*players;

// 	players = all_info->players;
// 	while (players)
// 	{
// 		if (players)
// 		players = players->next;
// 	}
// }

// static void		execute_fork_cmd(t_map *all_info, t_ps *ps)
// {
// 	int			first_arg;
// 	int			pc;


// 	// НЕ РАБОТАЕТ (аргуметы есть)
// 	// res = first_arg + second_arg;
// 	// ps->reg[ps->arg[THIRD_ARG] - 1] = res;
// }
