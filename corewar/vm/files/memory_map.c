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

static void			executing_ps(t_map *map, t_ps *ps)
{
	if (map->map[ps->pc] >= 1 && map->map[ps->pc] <= 16)
		g_cmd_arr[(int)map->map[ps->pc]](map, ps);
	else
		move_map_counter(&ps->pc, 1);
}

static void			run_players(t_map *map)
{
	t_ps			*ps;

	ps = map->ps;
	while (ps)
	{
<<<<<<< HEAD
		for( int i = 0; i < 50000000; i++);
		print_process(ps);
		executing_ps(map, ps);
		ps = ps->next;
=======
		// if (map->cycle % 1536 == 0)
		// 	printf("player %d total_lives: %d\n", player->player_num * -1, player->total_lives);
		ps = player->ps;
		while (ps)
		{

			executing_ps(map, ps);
			ps = ps->next;
		}
		player = player->next;
>>>>>>> 19619f4ccd7a5e58821c39203be9e3f9097b6e30
	}
}

void				memory_map(t_file *file, int total_players, t_flags *flags)
{
	t_map			*map;
<<<<<<< HEAD
	unsigned int	i;
	
	map = create_map();
	map->flags = flags;
	fill_map(file, map, total_players);
	// map->total_lives = total_players;
	while (map->total_lives != 0)
	{
		i = 1;
		while (i < map->cycle_to_die)
		{
			printf("cycle : %d\n", i);
			run_players(map);
			map->cycle++;
			i++;
		}
		if (map->total_lives > NBR_LIVE)
			map->cycle_to_die -= CYCLE_DELTA;
=======
	int				mask;

	mask = 2;
	map = create_map();
	map->flags = flags;
	fill_map(file, map, total_players);
	map->processes = total_players;
	introducing_print(file);
	while (map->cycle < 20000)
	{
		if (flags->v_flag == 1 && flags->n_flag != 1
			&& flags->b_flag != 1 && flags->d_flag != 1)
			if (flags->v_value & mask)
				ft_printf("It is now cycle %d\n",
				map->cycle);
		run_players(map);
		map->cycle++;
>>>>>>> 19619f4ccd7a5e58821c39203be9e3f9097b6e30
	}
	// print_map(map);
}