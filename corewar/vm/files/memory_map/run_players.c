/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by alatyshe          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		executing_ps(t_map *map, t_ps *ps)
{
	if (map->flags->java_flag)
		ft_printf("%d:%d:%d", ps->player_num, ps->pc, 1);
	if (!ps->skip_cmd && !ps->cycles_to_cmd && ps->cmd_in_hex)
		g_cmd_arr[(int)ps->cmd_in_hex](map, ps);
	if (!ps->cycles_to_cmd && !ps->skip_cmd
		&& map->map[ps->pc] >= 1 && map->map[ps->pc] <= 16)
	{
		ps->cmd_in_hex = map->map[ps->pc];
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

void			run_players(t_map *map)
{
	t_ps		*ps;
	t_ps		*temp;

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