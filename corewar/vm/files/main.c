/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"

int					check_command(t_ps *ps, t_map *map)
{
	if (map->map[ps->pc] >= 1 && map->map[ps->pc] <= 16)
	{		
		return (1);
	}
	return (0);
}

void				executing_ps(t_map *map, t_player *players, t_ps *ps)
{
	if (!check_command(ps, map))
		move_map_counter(&ps->pc, 1);
	else
	{
		if (map->map[ps->pc] == 1)
			live(map, players, ps);
		else if (map->map[ps->pc] == 2)
			ld(map, players, ps);
		else if (map->map[ps->pc] == 3)
			st(map, players, ps);
		else if (map->map[ps->pc] == 4)
			add(map, players, ps);
		else if (map->map[ps->pc] == 5)
			sub(map, players, ps);
		else if (map->map[ps->pc] == 6)
			and(map, players, ps);
		else if (map->map[ps->pc] == 7)
			or(map, players, ps);
		else if (map->map[ps->pc] == 8)
			xor(map, players, ps);
		else if (map->map[ps->pc] == 9)
			zjmp(map, players, ps);
		else if (map->map[ps->pc] == 10)
			;// ldi(map, players, ps);
		else if (map->map[ps->pc] == 11)
			sti(map, players, ps);
		else if (map->map[ps->pc] == 12)
			fork_cmd(map, players, ps);
		else if (map->map[ps->pc] == 13)
			lld(map, players, ps);
		else if (map->map[ps->pc] == 14)
			;// lldi(map, players, ps);
		else if (map->map[ps->pc] == 15)
			lfork(map, players, ps);
		else if (map->map[ps->pc] == 16)
			aff(map, players, ps);
	}
}

void				start_processes(t_map *map)
{
	t_player	*player;
	t_ps		*ps;

	player = map->players;
	while (player)
	{
		ps = player->ps;
		while (ps)
		{
			executing_ps(map, map->players, ps);
			ps = ps->next;
		}
		player = player->next;
	}
}

void				memory_map(t_file *file, int total_players, t_flags *f)
{
	t_map			*map;
	int				pos;
	int				distance;
	int				player_num;

	map = create_map();
	map->flags = f;
	fill_map(file, map, total_players);
	
	// print_map(map);
	// print_players(map->players);
	// printf("\n");
	while (map->cycle < 40)
	{
		// printf("cycle : %d\n", map->cycle);
		start_processes(map);
		map->cycle++;
		// printf("\n");
	}
	// print_map(map);
	// printf("\n");
	// print_players(map->players);

}

int				main(int argc, char **argv)
{
	t_file		*files;
	t_file		*copy_files;
	int			count_players;
	t_flags		*flags;

	files = NULL;
	flags = create_flags();
	count_players = 0;
	files = read_arguments(argc, argv, &count_players, flags);
	// print_flags(flags);
	memory_map(files, count_players, flags);
	return (0);
}
