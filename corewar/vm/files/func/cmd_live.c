/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_live_cmd(t_map *map, t_ps *ps);

void			cmd_live(t_map *map, t_ps *ps)
{
	int			pc;

	if (ps->cycles_to_cmd < g_tab[0].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}

	// printf("%sLIVE HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(map, ps);
	execute_live_cmd(map, ps);
	ps->pc = pc;

	null_commands_variables(ps);
}

static void		execute_live_cmd(t_map *map, t_ps *ps)
{
	t_player	*copy_players;
	char		mask;

	mask = 1;
	ps->check_live = 1;
	copy_players = map->players;
	while (copy_players)
	{
		if (ps->arg[0] == copy_players->player_num)
		{
			map->total_lives++;
			copy_players->total_lives++;
			if (all_info->flags->v_flag == 1 && all_info->flags->n_flag != 1
				&& all_info->flags->b_flag != 1 && all_info->flags->d_flag != 1)
				if (all_info->flags->v_value & mask)
					ft_printf("Player %d (%s) is said to be alive\n",
					copy_players->player_num * -1, copy_players->name);
			copy_players->last_live = all_info->cycle;
			return ;
		}
		copy_players = copy_players->next;
	}
}
