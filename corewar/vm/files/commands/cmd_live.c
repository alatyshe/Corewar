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

static void		print_flags_live(t_map *map, t_player *copy_players)
{
	if (map->flags->java_flag)
		ft_printf(":l:%d", copy_players->player_num);
	if (check_flags(map->flags, 'v', 1))
	{
		ft_printf("Player %d (%s) is said to be alive\n",
		copy_players->player_num * -1, copy_players->name);
	}
}

static void		execute_live_cmd(t_map *map, t_ps *ps)
{
	t_player	*copy_players;
	char		mask;

	mask = 1;
	map->total_lives++;
	ps->check_live = 1;
	copy_players = map->players;
	if (check_flags(map->flags, 'v', 4))
		ft_printf("P%5d | %s %d\n", ps->ps_num, "live", ps->arg[0]);
	while (copy_players)
	{
		if (ps->arg[0] == copy_players->player_num)
		{
			copy_players->total_lives++;
			map->winner = copy_players->name;
			map->winner_num = copy_players->player_num * -1;
			print_flags_live(map, copy_players);
			copy_players->last_live = map->cycle;
			return ;
		}
		copy_players = copy_players->next;
	}
}

int				cmd_live(t_map *map, t_ps *ps)
{
	int			pc;
	int			temp_pc;
	int			stop_moving;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	stop_moving = ps->skip_cmd;
	if (ps->skip_cmd == 0)
		execute_live_cmd(map, ps);
	print_v_flag_adv(map, ps, pc);
	ps->pc = pc;
	null_commands_variables(ps);
	return (stop_moving);
}
