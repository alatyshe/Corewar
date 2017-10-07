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
	int		mask = 255;

	printf("map[%04d]: [%02x]\n", ps->pc, map->map[ps->pc] & mask);
	if (map->map[ps->pc] >= 1 && map->map[ps->pc] <= 16)
	{		
		return (1);
	}
	return (0);
}

void				executing_ps(t_map *map, t_player *players, t_ps *ps)
{
	if (!check_command(ps, map))
		move_pc(ps, 1);
	else
	{
		if (map->map[ps->pc] == 1)
			live(map, players, ps);
		else if (map->map[ps->pc] == 2)
			ld(map, players, ps);
		// else if (map->map[ps->pc] == 3)
		// 	st(map, players, ps);
		// else if (map->map[ps->pc] == 4)
		// 	add(map, players, ps);
		// else if (map->map[ps->pc] == 5)
		// 	sub(map, players, ps);
		
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

void				memory_map(t_info *info, int total_players)
{
	t_map			*map;
	int				pos;
	int				distance;
	int				player_num;

	map = create_map();
	fill_map(info, map, total_players);
	
	print_map(map);
	print_players(map->players);
	printf("\n");
	while (map->cycle < 25)
	{
		printf("cycle : %d\n", map->cycle);
		start_processes(map);
		map->cycle++;
		printf("\n");
	}
	printf("\n");
	print_players(map->players);

}

int				main(int argc, char **argv)
{
	t_info		*files;
	t_info		*copy_files;
	int			count_players;

	files = NULL;
	count_players = 0;
	files = read_arguments(argc, argv, &count_players);
	memory_map(files, count_players);
	return (0);
}
