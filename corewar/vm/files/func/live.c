/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void			check_players(t_map *all_info, t_player *player, int value)
{
	t_player	*copy_players;

	copy_players = player;
	while (copy_players)
	{
		if (value == copy_players->player_num)
		{
			copy_players->total_lives++;
			copy_players->last_live = all_info->cycle;
			return ;
		}
		copy_players = copy_players->next;
	}
}

//	возвращает следющую позицию ячейки
void			live(t_map *all_info, t_player *player, t_ps *ps)
{
	int			i;
	int			value;

	ps->p_size = 5;
	if (ps->cycles_to_cmd < g_tab[0].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	ps->check_live = 1;

	printf("%sLIVE HAS BEEN USED BY:%s\n", GREEN, RESET);
	printf("%splayer:\t\t\t%d%s\n", GREEN, ps->player, RESET);
	printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	
	move_pc(ps, 1);
	value = exec_arg_value(all_info->map, ps, 4);
	check_players(all_info, player, value);

	print_process(ps);

	null_commands_variables(ps);
	ps->cycles_to_cmd = 0;
}