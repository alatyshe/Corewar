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
	int			temp_pc;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	if (ps->skip_cmd == 0)
		execute_live_cmd(map, ps);
	if (check_flags(map->flags, 'v', 16))
	{
		if (ps->pc == 0)
			ft_printf("ADV %d (0x0000 -> %#06x) ", pc - ps->pc, pc);
		else
			ft_printf("ADV %d (%#06x -> %#06x) ", pc - ps->pc, ps->pc, pc);
		while (temp_pc != pc)
		{
			printf("%02x ", map->map[temp_pc] & 255);
			move_map_counter(&temp_pc, 1);
		}
		printf("\n");
	}
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
	if (check_flags(map->flags, 'v', 4))
		ft_printf("P    %-d | %s %d\n", ps->ps_num, "live", ps->arg[0]);
	while (copy_players)
	{
		if (ps->arg[0] == copy_players->player_num)
		{
			copy_players->total_lives++;
			map->winner = copy_players->name;
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
