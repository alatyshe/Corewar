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
	if (!ps->skip_cmd && !ps->cycles_to_cmd && ps->cmd_in_hex)
	{
		// printf("\t%sUSE : |%s|%s\n", GREEN, g_tab[(int)ps->cmd_in_hex - 1].name , RESET);
		g_cmd_arr[(int)ps->cmd_in_hex](map, ps);
		// printf("ps->ps_num : %d\n", ps->ps_num);
	}

	if (!ps->cycles_to_cmd && !ps->skip_cmd
		&& map->map[ps->pc] >= 1 && map->map[ps->pc] <= 16)
	{
		ps->cmd_in_hex = map->map[ps->pc];
		// printf("\t%sHERE : |%s|%s\n", GREEN, g_tab[(int)ps->cmd_in_hex - 1].name , RESET);
		// printf("\t\t%sps->pc : |%d|%s\n", GREEN, ps->pc , RESET);
		ps->cycles_to_cmd = g_tab[ps->cmd_in_hex - 1].cycle;
	}
	if (ps->cycles_to_cmd)
		ps->cycles_to_cmd--;
	if (ps->cycles_to_cmd == 0
		&& (map->map[ps->pc] < 1 || map->map[ps->pc] > 16))
		move_map_counter(&ps->pc, 1);
		
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
			{
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", ps_current->ps_num, map->cycle, map->cycle_to_die);
				//Тут нужна ссылка в ps на player->last_live. Второй %d - разница между map->cycle_to_die
				// и player->last_live (для 1 cycle_to_die - в 2 раза больше?)
			}
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
			ps_before = ps_current;
			ps_current = ps_after;
			if (ps_after != NULL)
				ps_after = ps_after->next;
		}
	}
}

static void			run_players(t_map *map, unsigned int i)
{
	t_ps			*ps;
	t_ps			*temp;

	temp = NULL;
	ps = map->ps;
	while (ps)
	{
		if (i == 1)
			ps->check_live = 0;
		executing_ps(map, ps);
		if (i == map->cycle_to_die && ps->check_live == 0)
		{
			if (ps->next)
				temp = ps->next;
			else
				temp = NULL;
			// remove_ps(map, ps);
			ps = temp;
		}
		else
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
			if (map->cycle && check_flags(flags, 'v', 2))
				ft_printf("It is now cycle %d\n", map->cycle);
			run_players(map, i);
			print_map(map);
			map->cycle++;
			i++;
		}
		kill_processes(map);
		if (map->total_lives > NBR_LIVE)
		{
			map->cycle_to_die -= CYCLE_DELTA;
			if (map->cycle && check_flags(flags, 'v', 2))
				ft_printf("Cycle to die is now %d\n", map->cycle_to_die);
		}
	}
}