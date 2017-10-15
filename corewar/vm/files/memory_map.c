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
	if (ps->cycles_to_cmd)
		ps->cycles_to_cmd--;
	
	if (!ps->skip_cmd && !ps->cycles_to_cmd && ps->cmd_in_hex)
	{
		printf("USE\n");
		g_cmd_arr[(int)ps->cmd_in_hex](map, ps);
	}

	if (ps->cycles_to_cmd)
		;
	else if (!ps->cycles_to_cmd && !ps->skip_cmd
		&& map->map[ps->pc] >= 1 && map->map[ps->pc] <= 16)
	{
		ps->cmd_in_hex = map->map[ps->pc];
		printf("\t\t%sHERE : |%s|%s\n", GREEN, g_tab[(int)ps->cmd_in_hex - 1].name , RESET);
		printf("\t\t%sps->pc : |%d|%s\n", GREEN, ps->pc , RESET);
		ps->cycles_to_cmd = g_tab[ps->cmd_in_hex - 1].cycle;
	}
	else
		move_map_counter(&ps->pc, 1);
}

static void			run_players(t_map *map)
{
	t_ps			*ps;

	ps = map->ps;
	while (ps)
	{
		executing_ps(map, ps);
		ps = ps->next;
	}
}

void				memory_map(t_file *file, int total_players, t_flags *flags)
{
	t_map			*map;
	unsigned int	i;

	map = create_map();
	map->flags = flags;
	fill_map(file, map, total_players);
	introducing_print(file);
	map->total_lives = total_players;
	while (map->total_lives != 0)
	{
		i = 1;
		map->total_lives = 0;
		while (i <= map->cycle_to_die)
		{
			// printf("cycle : %d\n", map->cycle);
			// if (flags->v_flag && !flags->n_flag && !flags->b_flag && !flags->d_flag)
			if (map->cycle && check_flags(flags, 'v', 2))
				ft_printf("It is now cycle %d\n", map->cycle);
			run_players(map);
			print_map(map);
			map->cycle++;
			i++;
		}
		if (map->total_lives > NBR_LIVE)
			map->cycle_to_die -= CYCLE_DELTA;
		print_info_map(map);
	}
	// print_map(map);
}