/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lfork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_lfork(t_map *map, t_ps *ps);

void			cmd_lfork(t_map *map, t_ps *ps)
{
	int			pc;

	if (ps->cycles_to_cmd < g_tab[14].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	
	printf("%sLFORK HAS BEEN USED BY:%s\n", GREEN, RESET);
	// print_process(ps);

	pc = fill_commands(map, ps);
	execute_lfork(map, ps);
	ps->pc = pc;

	null_commands_variables(ps);
}

static void		execute_lfork(t_map *map, t_ps *ps)
{
	t_ps		*ps_new;
	int			distance;
	int			pc;

	ps_new = create_ps(0, 0, map->ps_counter++);
	ps_new->next = map->ps;
	map->ps = ps_new;

	ps_new->player_num = ps->player_num;
	ps_new->check_live = ps->check_live;
	ps_new->carry = ps->carry;

	pc = ps->pc;
	distance = ps->arg[FIRST_ARG];
	move_map_counter(&pc, distance);
	ps_new->pc = pc;

	map->processes++;
	// move_map_counter(&ps_new->pc, ps->arg[FIRST_ARG]);
}
