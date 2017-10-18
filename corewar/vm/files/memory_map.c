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
	printf("\t%sat : [%02x]\n", RED,map->map[ps->pc]);
	printf("\t%sPS_NUM: |%d|%s\n", MAGENTA, ps->ps_num, RESET);
	printf("\t%sy     : |%d|%s\n", MAGENTA, ps->pc / 64 , RESET);
	printf("\t%sx     : |%d|%s\n", MAGENTA, ps->pc % 64 , RESET);
	print_process (ps);
	if (map->flags->java_flag)
		ft_printf("%d:%d:%d", ps->player_num, ps->pc, 1);
	if (!ps->skip_cmd && !ps->cycles_to_cmd && ps->cmd_in_hex)
	{
		printf("\t%sUSE : |%s|%s\n", GREEN, g_tab[(int)ps->cmd_in_hex - 1].name , RESET);
		g_cmd_arr[(int)ps->cmd_in_hex](map, ps);
		// printf("ps->ps_num : %d\n", ps->ps_num);
	}

	if (!ps->cycles_to_cmd && !ps->skip_cmd
		&& map->map[ps->pc] >= 1 && map->map[ps->pc] <= 16)
	{
		ps->cmd_in_hex = map->map[ps->pc];
		printf("\t%sHERE : |%s|%s\n", GREEN, g_tab[(int)ps->cmd_in_hex - 1].name , RESET);
		// printf("\t%sps->pc : |%d|%s\n", GREEN, ps->pc , RESET);
		ps->cycles_to_cmd = g_tab[ps->cmd_in_hex - 1].cycle;
	}
	if (ps->cycles_to_cmd)
		ps->cycles_to_cmd--;
	if (ps->cycles_to_cmd == 0
		&& (map->map[ps->pc] < 1 || map->map[ps->pc] > 16))
		move_map_counter(&ps->pc, 1);
	
	if (map->flags->java_flag)
		ft_printf(";");
}

static void			kill_processes(t_map *map)
{
	t_ps			*ps_before;
	t_ps			*ps_current;
	t_ps			*ps_after;

	ps_before = NULL;
	ps_current = map->ps;
	ps_after = map->ps->next;
	while (ps_current)
	{
		if (ps_current->check_live == 0)
		{
			if (check_flags(map->flags, 'v', 8))
				ft_printf("Process %d has lived for %d cycles (CTD %d)\n", ps_current->ps_num, ps_current->cycles, map->cycle_to_die);
			free_process(ps_current);
			if (ps_before)
				ps_before->next = ps_after;
			else
				map->ps = ps_after;
			ps_current = ps_after;
			if (ps_after != NULL)
				ps_after = ps_after->next;
		}
		else
		{
			ps_current->check_live = 0;
			ps_before = ps_current;
			ps_current = ps_after;
			if (ps_after != NULL)
				ps_after = ps_after->next;
		}
	}
}

static void			run_players(t_map *map)
{
	t_ps			*ps;
	t_ps			*temp;

	temp = NULL;
	ps = map->ps;
	while (ps)
	{
		executing_ps(map, ps);
		ps->cycles++;
		ps = ps->next;
	}
	if (map->flags->java_flag)
		ft_printf("\n");
}

void				memory_map(t_file *file, int total_players, t_flags *flags)
{
	t_map			*map;
	int				i;

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
		while (i <= map->cycle_to_die)
		{
			if (map->cycle && check_flags(flags, 'v', 2))
				ft_printf("It is now cycle %d\n", map->cycle);
			run_players(map);
			print_map(map);
			map->cycle++;
			i++;
		}
		kill_processes(map);
		if (map->total_lives > NBR_LIVE || !map->checks)
		{
			map->cycle_to_die -= CYCLE_DELTA;
			map->checks = 10;
			if (flags->java_flag)
				ft_printf("(%d)\n", map->cycle_to_die);
			if (map->cycle && check_flags(flags, 'v', 2))
				ft_printf("Cycle to die is now %d\n", map->cycle_to_die);
		}
		i = 1;
		map->checks--;
	}
	ft_printf("Ёбать Contestant 1, \"%s\", has won !\n", map->winner);
}