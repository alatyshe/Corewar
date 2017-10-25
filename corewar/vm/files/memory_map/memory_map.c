/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by alatyshe          #+#    #+#             */
/*   Updated: 2017/10/24 16:15:24 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		nulling_players_lives(t_player *players)
{
	t_player	*copy_player;

	copy_player = players;
	while (copy_player)
	{
		copy_player->total_lives = 0;
		copy_player = copy_player->next;
	}
}

static void		cycle_reducing(t_map *map, t_flags *flags)
{
	map->cycle_to_die -= CYCLE_DELTA;
	map->checks = 10;
	if (flags->n_flag)
		cycle_to_die(map->cycle_to_die);
	if (map->cycle && check_flags(flags, 'v', 2))
		ft_printf("Cycle to die is now %d\n", map->cycle_to_die);
}

static void		run_cycles_to_die(t_map *map, t_flags *flags, int i)
{
	while (i <= map->cycle_to_die)
	{
		if (flags->n_flag)
		{
			cycle(map);
			if (map->cycle % 50 == 0)
				ref(map);
		}
		if (map->cycle && check_flags(flags, 'v', 2))
			ft_printf("It is now cycle %d\n", map->cycle);
		run_players(map);
		print_map_s_flag(map);
		map->cycle++;
		i++;
	}
}

static void		map_running(t_map *map, t_flags *flags)
{
	int			i;

	i = 0;
	while (map->total_lives != 0)
	{
		if (map->flags->db_flag)
			print_players(map->players, map);
		map->total_lives = 0;
		run_cycles_to_die(map, flags, i);
		nulling_players_lives(map->players);
		kill_processes(map);
		if (map->total_lives >= NBR_LIVE || !map->checks)
			cycle_reducing(map, flags);
		if (flags->java_flag)
			ft_printf("(%d)\n", map->cycle_to_die);
		i = 1;
		map->checks--;
	}
}

void			memory_map(t_file *file, int total_players, t_flags *flags)
{
	t_map		*map;

	map = create_map();
	map->flags = flags;
	fill_map(file, map, total_players);
	if (!flags->java_flag)
		introducing_print(file);
	if (flags->n_flag)
		visual(map, total_players, file);
	map->total_lives = total_players;
	if (flags->java_flag)
		print_map_java(map, file);
	map_running(map, flags);
	if (flags->n_flag)
		winner(map->winner);
	if (flags->java_flag == 0)
		ft_printf("Contestant %d, \"%s\", has won !\n",
			map->winner_num, map->winner);
	else if (flags->java_flag == 1)
		ft_printf("-%d has won\n", map->winner_num);
}
