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

static void		free_process(t_ps *ps)
{
	free(ps->reg);
	free(ps->arg);
	free(ps->arg_types);
	free(ps);
}

// static void		move_ps()

void			kill_processes(t_map *map)
{
	t_ps		*ps_before;
	t_ps		*ps_current;
	t_ps		*ps_after;

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
			ps_after = (ps_after != NULL) ? ps_after->next : NULL;
		}
		else
		{
			ps_current->check_live = 0;
			ps_before = ps_current;
			ps_current = ps_after;
			ps_after = (ps_after != NULL) ? ps_after->next : NULL;
		}
	}
}
