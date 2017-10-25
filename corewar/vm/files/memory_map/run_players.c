/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by alatyshe          #+#    #+#             */
/*   Updated: 2017/10/24 16:13:28 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		check_execute_ps(t_map *map, t_ps *ps)
{
	if (map->flags->java_flag)
		ft_printf("%d:%d:%d", ps->player_num, ps->pc, 1);
	
	if (ps->cycles_to_cmd == 0 && ps->cmd_in_hex == 0
		&& (map->map[ps->pc] < 1 || map->map[ps->pc] > 16))
	{
		move_map_counter(&ps->pc, 1);
		// ft_printf("%s[P%5d][PC%5d][0x%02x]%s\n",CYAN, ps->ps_num, ps->pc, map->map[ps->pc] & 255, RESET);
	}
	
	if (!ps->cycles_to_cmd && ps->cmd_in_hex)
	{
		// ft_printf("%s[P%5d] %s",RED,  ps->ps_num, RESET);
		g_cmd_arr[(int)ps->cmd_in_hex](map, ps);
		// ft_printf("%s[P%5d][PC%5d][0x%02x]%s\n",RED, ps->ps_num, ps->pc, map->map[ps->pc] & 255,RESET);
	}

	if (ps->cycles_to_cmd)
		ps->cycles_to_cmd--;
	if (map->flags->java_flag)
		ft_printf(";");
}

static void		check_opcodes(t_map *map)
{
	t_ps		*ps;
	t_ps		*temp;

	temp = NULL;
	ps = map->ps;
	while (ps)
	{
		if (!ps->cycles_to_cmd && !ps->cmd_in_hex
			&& map->map[ps->pc] >= 1 && map->map[ps->pc] <= 16)
		{
			// ft_printf("%sI FIND THIS CMD [%02x][P%5d]",GREEN, map->map[ps->pc], ps->ps_num);
			// ft_printf("[PC%5d]",ps->pc);
			// ft_printf("[CYCLES%5d]%s\n", g_tab[map->map[ps->pc] - 1].cycle, RESET);
			ps->cmd_in_hex = map->map[ps->pc];
			ps->cycles_to_cmd = g_tab[ps->cmd_in_hex - 1].cycle - 1;
		}
		ps = ps->next;
	}
}

static void		execute_cmds(t_map *map)
{
	t_ps		*ps;
	t_ps		*temp;

	temp = NULL;
	ps = map->ps;
	while (ps)
	{
		if (map->flags->db_flag)
			print_process(ps);
		if (map->flags->n_flag)
			cursor_from_map(ps->pc, map->map, map->clr);//NCURSES
		check_execute_ps(map, ps);
		if (map->flags->n_flag)
			cursor_on_map(ps->pc, ps->player_num * -1, map->map, map->clr);
		ps->cycles++;
		ps = ps->next;
	}
	if (map->flags->java_flag)
		ft_printf("\n");
}


void			run_players(t_map *map)
{
	execute_cmds(map);
	check_opcodes(map);
}
