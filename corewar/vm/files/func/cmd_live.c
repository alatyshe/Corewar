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

	// проверка кодирующего бита
	
	// printf("%sLIVE HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(map, ps);
	execute_live_cmd(map, ps);
	print_v_flag(ps->pc, pc, ps);
	ps->pc = pc;

	null_commands_variables(ps);
}

static void		execute_live_cmd(t_map *map, t_ps *ps)
{
	t_player	*copy_players;
	char		mask;

	mask = 1;
	map->total_lives++;
	ps->check_live = 1;
	copy_players = map->players;
	while (copy_players)
	{
		if (ps->arg[0] == copy_players->player_num)
		{
			copy_players->total_lives++;
			if (check_flags(map->flags, 'v', 1))
			{
				ft_printf("Player %d (%s) is said to be alive\n",
				copy_players->player_num * -1, copy_players->name);
			}
			copy_players->last_live = map->cycle;
			return ;
		}
		copy_players = copy_players->next;
	}
}
