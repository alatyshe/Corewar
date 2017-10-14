/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"

static int		check_command(t_ps *ps, t_map *map)
{
	if (map->map[ps->pc] >= 1 && map->map[ps->pc] <= 16)
	{		
		return (1);
	}
	return (0);
}

static void		executing_ps(t_map *map, t_ps *ps)
{
	if (!check_command(ps, map))
		move_map_counter(&ps->pc, 1);
	else
	{
		if (map->map[ps->pc] == 1)
			cmd_live(map, ps);
		else if (map->map[ps->pc] == 2)
			cmd_ld(map, ps);
		else if (map->map[ps->pc] == 3)
			cmd_st(map, ps);
		else if (map->map[ps->pc] == 4)
			cmd_add(map, ps);
		else if (map->map[ps->pc] == 5)
			cmd_sub(map, ps);
		else if (map->map[ps->pc] == 6)
			cmd_and(map, ps);
		else if (map->map[ps->pc] == 7)
			cmd_or(map, ps);
		else if (map->map[ps->pc] == 8)
			cmd_xor(map, ps);
		else if (map->map[ps->pc] == 9)
			cmd_zjmp(map, ps);
		else if (map->map[ps->pc] == 10)
			cmd_ldi(map, ps);
		else if (map->map[ps->pc] == 11)
			cmd_sti(map, ps);
		else if (map->map[ps->pc] == 12)
			cmd_fork(map, ps);
		else if (map->map[ps->pc] == 13)
			cmd_lld(map, ps);
		else if (map->map[ps->pc] == 14)
			cmd_lldi(map, ps);
		else if (map->map[ps->pc] == 15)
			cmd_lfork(map, ps);
		else if (map->map[ps->pc] == 16)
			cmd_aff(map, ps);
	}
}

static void		run_players(t_map *map)
{
	t_player	*player;
	t_ps		*ps;

	player = map->players;
	while (player)
	{
		ps = player->ps;
		while (ps)
		{
			executing_ps(map, ps);
			ps = ps->next;
		}
		player = player->next;
	}
}

void				memory_map(t_file *file, int total_players, t_flags *flags)
{
	t_map			*map;

	map = create_map();
	map->flags = flags;
	fill_map(file, map, total_players);

	while (map->cycle < 40)
	{
		run_players(map);
		map->cycle++;
	}
	print_map(map);
}