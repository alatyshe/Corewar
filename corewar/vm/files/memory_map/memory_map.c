/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by alatyshe          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by alatyshe         ###   ########.fr       */
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
	if (flags->java_flag)
		ft_printf("(%d)\n", map->cycle_to_die);
	if (map->cycle && check_flags(flags, 'v', 2))
		ft_printf("Cycle to die is now %d\n", map->cycle_to_die);
}

static void		run_cycles_to_die(t_map *map, t_flags *flags, int i)
{
	while (i <= map->cycle_to_die)
	{
		if (map->cycle && check_flags(flags, 'v', 2))
			ft_printf("It is now cycle %d\n", map->cycle);
		run_players(map);
		print_map(map);
		map->cycle++;
		i++;
	}
}

void			memory_map(t_file *file, int total_players, t_flags *flags)
{
	t_map		*map;
	int			i;

	i = 0;
	map = create_map();
	map->flags = flags;
	fill_map(file, map, total_players);
	if (!flags->java_flag)
		introducing_print(file);
	map->total_lives = total_players;
	if (flags->java_flag)
		print_map_java(map, file);
	while (map->total_lives != 0)
	{
		map->total_lives = 0;
		run_cycles_to_die(map, flags, i);
		nulling_players_lives(map->players);
		kill_processes(map);
		if (map->total_lives > NBR_LIVE || !map->checks)
			cycle_reducing(map, flags);
		i = 1;
		map->checks--;
	}
	ft_printf("Contestant 1, \"%s\", has won !\n", map->winner);
}
